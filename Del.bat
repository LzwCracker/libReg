@echo off
del /f /ah "%~dp0*.suo" 
del /f "%~dp0*.positions"
del /f "%~dp0*.gitattributes"
del /f "%~dp0*.gitignore"
del /f  "%~dp0*.sdf"
del /f   "%~dp0*.aps"
del /f   "%~dp0*.opt"
del /f   "%~dp0*.ncb"
del /f   "%~dp0*.user"
del /f   "%~dp0*.user"
del /f /ah "%~dp0*.user"
rd /q /s "%~dp0Debug"
rd /q /s "%~dp0Release"
rd /q /s "%~dp0.vs"
rd /q /s "%~dp0.git"
rd /q /s "%~dp0x64"

