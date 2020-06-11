#include <random>
#include "Fern.h"

Fern::Fern() {

}

void Fern::init() {

}

void Fern::draw_and_calculate(sf::RenderWindow* window) {
    sf::CircleShape pp(0.5f);
    pp.setFillColor(sf::Color::Green);
    pp.setPosition(100 * prev_x + 700, -76 * prev_y + 850);
    window->draw(pp);
    float r = rand() % 100;
    float xn = prev_x;
    float yn = prev_y;
    if (r < 1) {
        prev_x = 0;
        prev_y = 0.16 * yn;
    }
    else if (r < 86) {
        prev_x = 0.85 * xn + 0.04 * yn;
        prev_y = -0.04 * xn + 0.85 * yn + 1.6;
    }
    else if (r < 93) {
        prev_x = 0.20 * xn - 0.26 * yn;
        prev_y = 0.23 * xn + 0.22 * yn + 1.6;
    }
    else {
        prev_x = -0.15 * xn + 0.28 * yn;
        prev_y = 0.26 * xn + 0.24 * yn + 0.44;
    }
}