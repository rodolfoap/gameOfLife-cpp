#include <iostream>
void initscreen() {
	std::cerr<<std::endl;
}
void updatescreen(){
	std::cerr<<std::endl;
}
void setdot(int y, int x, int v){
	if(x==0) std::cerr<<std::endl;
	std::cerr<<(v?'#':'.');  
}
