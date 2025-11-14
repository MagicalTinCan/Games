@echo off

set directory=%~1

rem echo %directory%

cd %directory%

git add data.txt > NUL
git commit -q -m "Action" > NUL
git push -q > NUL