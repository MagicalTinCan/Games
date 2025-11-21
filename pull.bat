@echo off

rem Program made by Samuel Campbell

set directory=%~1

cd %directory%

git pull -q

rem echo %directory%