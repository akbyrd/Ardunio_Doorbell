#include <SD.h>
#include "filedata.h"

int csPin = 4;
char fileName[] = "test2.txt";

void setup() {
  pinMode(csPin, OUTPUT); //Required for SD functionality 
  SD.begin(csPin);
  Serial.begin(9600);

  printAllFiles(); 
}

void loop() {
}

void printAllFiles() {
  File root = SD.open("/");
  
  while(true) {
    File file = root.openNextFile();
    
    if (file) {
      if (file.isDirectory()) {
        Serial.print("Skipping directory: ");
        Serial.println(file.name());
      }
      else {
        Serial.print(file.name());
        Serial.print("\t");
        Serial.println(file.size());
      }
    }
    else {
      Serial.println("No more files");
      return;
    }
  }
}

void printTestFile() {
  File file = SD.open(fileName);
  if ( !file ) Serial.println("Open failed");
  Serial.print(fileName);
  Serial.print(" size: ");
  Serial.println(file.size());
  
  while(file.available()) {
    Serial.println(file.read());
  }
}

void test() {
  SD.remove("Test.txt");
  File file = SD.open("Test.txt", FILE_WRITE);
  Serial.print("Writing ");
  Serial.print(file.write(filedata, sizeof(filedata)/sizeof(unsigned char)));
  Serial.println(" bytes");

  file.seek(0);
  while(file.available()) {
    Serial.println(file.read());
  }

  file.close();
}
