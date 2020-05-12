#include <iostream>
#include <fstream>
#include <string.h>
#include <unistd.h>
#define B(p, q)(b[y+p][x+q]=='#')

class GameOfLife{
private:
	int col=0, row=0;
	char b[128][256];
	int i[128][256]{0};
public:
	GameOfLife(char* v);
	void calculate_i();
	void calculate_b();
};