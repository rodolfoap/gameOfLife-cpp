#include <fstream>
#include <string.h>

#define HEIGHT 48
#define WIDTH 230

class GameOfLife{
private:
	char b[HEIGHT][WIDTH];
	char t[HEIGHT][WIDTH];
	int i[HEIGHT][WIDTH];
public:
	GameOfLife(char* v);
	void calculate_i();
	void calculate_b();
};
