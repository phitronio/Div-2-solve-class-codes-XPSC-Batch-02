@echo off
cls
set /p file=Enter The Name of the first file:%=%
set /p file2=Enter The Name of the second file:%=%
g++ -o test_gen test_gen.cpp
g++ -o %file% %file%.cpp
g++ -o %file2% %file2%.cpp
:start
test_gen.exe
%file% <input.txt> out1.txt
%file2% <input.txt> out2.txt

fc out1.txt out2.txt > nul
if errorlevel 1 goto files_differ
echo Test Case OK
goto start


:files_differ
echo !ERROR ENCOUNTERED!
pause


