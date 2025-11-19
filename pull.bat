@echo off

set directory=%~1

cd %directory%

git pull -q

rem echo %directory%