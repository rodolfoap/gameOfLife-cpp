#include <iostream>
#include <fstream>
#include <string.h>
#include <unistd.h>
#define B(p, q)(b[y+p][x+q]=='#')

class GameOfLife{
public:
	int col=0, row=0;
	char b[128][256];
	int i[128][256]{0};
	GameOfLife(char* v){
		std::ifstream f(v);
		while(f>>b[row++]);
		col=strlen(b[0]);
	}
	void calculate_i(){
		memset(i, 0, sizeof(i));
		for(int y=0; y<row; ++y) { for(int x=0; x<col; ++x) {
			i[y][x]=B(-1,-1)+B(-1,0)+B(-1,1)+B(0,-1)+B(0,1)+B(1,-1)+B(1,0)+B(1,1);
			setdot(y, x, b[y][x]=='#'?1:0);
		}}
	}
	void calculate_b(){
		for(int y=0; y<row; ++y) { for(int x=0; x<col; ++x) {
			// Apply life rules
			switch(i[y][x]) {
				case 3: b[y][x]='#'; break;
				case 2: break;
				default: b[y][x]='.';
			}
		}}
	}
};
