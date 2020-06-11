#include <SFML\Graphics.hpp>
#include <time.h> 
#include <random>
#include <iostream>
#include <vector>
#include "Serpinsky.h"
#include "fern.h"

sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML works!");

int main() {
    srand(time(0));
    sf::Clock clock;
    /*
    //int number of vertices, float coefficient
    Serpinsky *SF = new Serpinsky(3, 1);
    SF->init();
    */
    Fern* fern = new Fern();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        sf::Time time = clock.getElapsedTime();
        std::cout << 1.f / time.asSeconds() << std::endl;
        clock.restart().asSeconds();
        //SF->draw_and_calculate(&window);
        fern->draw_and_calculate(&window);
        window.display();
    }
	return 0;
}