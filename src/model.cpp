#include "view.hpp"
#include "model.hpp"
#define B(p, q)(b[y+p][x+q]=='#')

GameOfLife::GameOfLife(char* v){
	std::ifstream f(v);
	while(f>>b[row++]);
	col=strlen(b[0]);
}

void GameOfLife::calculate_i(){
	memset(i, 0, sizeof(i));
	for(int y=0; y<row; ++y) { for(int x=0; x<col; ++x) {
		i[y][x]=B(-1,-1)+B(-1,0)+B(-1,1)+B(0,-1)+B(0,1)+B(1,-1)+B(1,0)+B(1,1);
		setdot(y, x, b[y][x]=='#'?1:0);
	}}
}

void GameOfLife::calculate_b(){
	for(int y=0; y<row; ++y) { for(int x=0; x<col; ++x) {
		switch(i[y][x]) {
			case 3: b[y][x]='#'; break;
			case 2: break;
			default: b[y][x]='.';
		}
	}}
}
