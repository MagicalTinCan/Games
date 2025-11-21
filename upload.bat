@echo off

rem Program made by Samuel Campbell

set directory=%~1
set file=%~2

rem echo %directory%

cd %directory%

git add %file% > NUL
git commit -q -m "Action" > NUL
git push -q > NUL