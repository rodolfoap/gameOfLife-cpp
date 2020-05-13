#include "view.hpp"
#include "model.hpp"
#define B(p, q)(b[y+p][x+q]=='#')

GameOfLife::GameOfLife(char* v){
	int col=0, row=0;
	// Read file into matrix f
	std::ifstream f(v);
	while(f>>t[row++]); row--; col=strlen(t[0]);
	// Move matrix f to the center of matrix b
	memset(b, '.', WIDTH*HEIGHT-3);
	for(int m=0; m<HEIGHT; m++) b[m][WIDTH-1]=0;
	for(int m=0; m<row; m++) for(int n=0; n<col; n++) b[(HEIGHT-row)/2+m][(WIDTH-col)/2+n]=t[m][n];
}
// Calculate the neighbours amount
void GameOfLife::calculate_i(){
	memset(i, 0, sizeof(i));
	for(int y=0; y<HEIGHT; ++y) { for(int x=0; x<WIDTH; ++x) {
		i[y][x]=B(-1,-1)+B(-1,0)+B(-1,1)+B(0,-1)+B(0,1)+B(1,-1)+B(1,0)+B(1,1);
		setdot(y, x, b[y][x]=='#'?1:0);
	}}
}
// Make each cell evolve
void GameOfLife::calculate_b(){
	for(int y=0; y<HEIGHT; ++y) { for(int x=0; x<WIDTH; ++x) {
		switch(i[y][x]) {
			case 3: b[y][x]='#'; break;
			case 2: break;
			default: b[y][x]='.';
		}
	}}
}
