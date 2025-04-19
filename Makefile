all:
	g++ -I include -L lib -o main main.cpp -lmingw32 -lSDL3