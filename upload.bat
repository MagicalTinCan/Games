@echo off

set directory=%~1

echo %directory%

cd %directory%

git add data.txt
git commit -m "Action"
git push