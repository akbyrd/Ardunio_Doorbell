@echo off
REM cls

REM Delete old output
echo Deleting old Input and Output
del /Q Sounds\Input\
del /Q Sounds\Output\
echo.

REM Resample original .wavs
echo Resampling originals
pushd Sounds\Originals\
for %%f in (*.wav) do (
	echo     %%f
	..\..\ssrc.exe --quiet --rate 8000 "%%f" "..\Input\%%~nf.wav"
)
popd
echo.

REM Process resulting .wavs
echo Processing sounds
pushd Sounds\Input\
for %%f in (*.wav) do (
	echo     %%f
	..\..\Wave2C.exe "%%f" "..\Output\%%~nf.h" "soundData"
)
popd
echo.

echo Complete
echo.
pause