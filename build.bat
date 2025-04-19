@echo off
cls
echo Building...
g++ -I src/include -L src/lib -o main main.cpp -lmingw32  -lSDL3
echo Done!
pause
cls