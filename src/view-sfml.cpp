#include<SFML/Graphics.hpp>

sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
sf::CircleShape dot(4);

void initscreen() {
        dot.setFillColor(sf::Color(0, 96, 96));
        window.clear();
}

void updatescreen(){
        window.display();
}

void setdot(int y, int x, int v){
        dot.setFillColor(v?sf::Color(0, 255, 0):sf::Color(0, 0, 0));
	dot.setPosition(x*10, y*10);
	window.draw(dot);
}
