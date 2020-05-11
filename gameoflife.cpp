#include <iostream>
#include <fstream>
#include <string.h>
#include <unistd.h>
#define B(p, q)(b[y+p][x+q]=='#')
int main(int n, char**v) {
	int col=0, row=0;
	char b[128][256];
	std::ifstream f(v[1]);
	while(f>>b[row++]);
	col=strlen(b[0]);
	while(1) {
		std::cout<<"\033[2J\033[1;1H"; // Clear Screen

		// Calculate neighbors number and print actual state
		int i[128][256]{0};
		for(int y=0; y<row; ++y) { for(int x=0; x<col; ++x) {
			i[y][x]=B(-1,-1)+B(-1,0)+B(-1,1)+B(0,-1)+B(0,1)+B(1,-1)+B(1,0)+B(1,1);
			std::cerr<<b[y][x];
		} std::cerr<<std::endl; } std::cerr<<std::endl;

		// Apply rules over neighbors number
		for(int y=0; y<row; ++y) { for(int x=0; x<col; ++x) {
			// Apply life rules
			switch(i[y][x]) {
				case 3: b[y][x]='#'; break;
				case 2: break;
				default: b[y][x]='.';
			}
		} } usleep(200000);
	}
}
