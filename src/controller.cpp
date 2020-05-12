#include <fstream>
#include <string.h>
#include <unistd.h>
#include "view.hpp"
#include "model.hpp"
#define B(p, q)(b[y+p][x+q]=='#')

int main(int n, char**v) {
	GameOfLife game(v[1]);
	initscreen();
	while(1) {
		game.calculate_i();
		updatescreen();
		game.calculate_b();
		usleep(200000);
	}
}
