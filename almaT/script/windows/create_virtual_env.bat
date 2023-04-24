set CURRENT_DIRECTORY=%1
set CURRENT_BINARY_DIRECTORY=%2
set LIB_DIR=%3

set CURRENT_DIRECTORY=%CURRENT_DIRECTORY:/=\%
set CURRENT_BINARY_DIRECTORY=%CURRENT_BINARY_DIRECTORY:/=\%
set LIB_DIR=%LIB_DIR:/=\%

if exist "%CURRENT_BINARY_DIRECTORY%\venv3" (
	rmdir /s %CURRENT_BINARY_DIRECTORY%\venv3 /q
)
virtualenv %CURRENT_BINARY_DIRECTORY%\venv3 -p python3
%CURRENT_BINARY_DIRECTORY%\venv3\Scripts\pip.exe install --no-index --find-links="%LIB_DIR%" -r %CURRENT_DIRECTORY%\requirements.txt 