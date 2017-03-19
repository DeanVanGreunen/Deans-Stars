#include <SFML/Graphics.hpp>
#include "Stars3D.hpp"
#include <chrono>

int main(){
    sf::RenderWindow window(sf::VideoMode(3200, 2400), "Dean's Stars <3", sf::Style::Fullscreen);
    Stars3D *stars3d = new Stars3D(1000, 100.0f, 0.01f);
	auto t1 = std::chrono::high_resolution_clock::now();
   	while (window.isOpen()){
		sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed) window.close();
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape) && (event.key.shift && event.key.alt && event.key.system)) window.close();
        };			
		auto t2 = std::chrono::high_resolution_clock::now();
		float delta = (float)std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count();
		window.clear(sf::Color(0, 0, 0, 255));
    	stars3d->work(&window, delta);
        window.display();
        t1 = t2;
    };
    return 0;
};
