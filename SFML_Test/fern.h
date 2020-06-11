#pragma once
#include <SFML\Graphics.hpp>
#include <vector>

class Fern
{
public:
    Fern();
    void init();
    void draw_and_calculate(sf::RenderWindow* window);
private:
    float prev_x = 0;
    float prev_y = 0;
};
