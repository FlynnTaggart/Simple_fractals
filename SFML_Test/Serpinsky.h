#pragma once
#include <SFML\Graphics.hpp>
#include <vector>

class Serpinsky{
public:
    Serpinsky(int number_of_vertices, float coefficient);
    void init();
    void draw_and_calculate(sf::RenderWindow* window);
private:
    int points_cnt = 3;
    float h = 1;
    std::vector<sf::CircleShape> points;
    sf::CircleShape pp;
    float prev_x = rand() % 1024;
    float prev_y = rand() % 768;
};

