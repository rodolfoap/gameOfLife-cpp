#include <iostream>
void initscreen() {
	std::cerr<<std::endl;
}
void updatescreen(){
	std::cout<<"\033[2J\033[1;1H"; // Clear Screen
}
void setdot(int y, int x, int v){
	if(x==0&&y!=0) std::cerr<<std::endl;
	std::cerr<<(v?'#':'.');  
}
