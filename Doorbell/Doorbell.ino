#include <avr/interrupt.h>
#include <avr/sleep.h>
#include "audio.h"

//TODO:
  //Power draw? (measure, try lower power modes)
  //Debouncing

/* PWM, analogWrite() disabled on pins 3, 9, 10, 11 */

/* Pins in use */
  //motionSensorPin = A0
  //int speakerPin = 11;
  int sensorTriggerValue = 300;
  int interruptPin = 0; //Really pin 2
  
unsigned long int lastPlayTime = 0;
unsigned long int timeDelay = 5000;              //5 second delay between sounds
unsigned long int interruptDelay = 250;          //20 ms delay for debouncing
volatile boolean recentInterrupt = false;

void interruptHandler()
{
  recentInterrupt = true;
}

void setup()
{
  attachInterrupt(interruptPin, interruptHandler, RISING);
}

void loop()
{
  if (recentInterrupt)
  {
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);         //Set sleep mode
    sleep_enable();                              //Enable global sleep bit
    delay(interruptDelay);                       //Delay for debouncing before sleep
    sleep_mode();                                //Go to sleep
    
    //The device is sleeping now until signal rises on pin 2
    
    sleep_disable();
    startPlayback();
    lastPlayTime = millis();
    delay(interruptDelay);                       //Debounce on wake as well
    recentInterrupt = false;
  }

  int sensorValue = analogRead(A0);
  
  if (millis() - lastPlayTime > timeDelay) {
    if (sensorValue > sensorTriggerValue) {
      startPlayback();
      lastPlayTime = millis();
    }
  }
  
  delay(30);                                     //Slow polling, plus debouncing
}
