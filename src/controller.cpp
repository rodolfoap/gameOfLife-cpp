#include <unistd.h>
#include "view.hpp"
#include "model.hpp"

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
