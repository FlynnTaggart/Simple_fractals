#include <random>
#include "Serpinsky.h"


Serpinsky::Serpinsky(int number_of_vertices, float coefficient) {
    points_cnt = number_of_vertices;
    h = coefficient;
}
void Serpinsky::init() {
    for (int i = 0; i < points_cnt; ++i) {
        sf::CircleShape point(4.f);
        point.setFillColor(sf::Color::Green);
        float x = 0, y = 0;
        x = rand() % 1024;
        y = rand() % 768;
        while (0.5 * (x - 512) * (x - 512) + (y - 384) * (y - 384) < 324 * 324) {
            x = rand() % 1024;
            y = rand() % 768;
        }
        point.setPosition(x, y);
        points.push_back(point);
    }
    float prev_x = rand() % 1024;
    float prev_y = rand() % 768;
}
void Serpinsky::draw_and_calculate(sf::RenderWindow *window) {
    int pnt = rand() % points_cnt;
    float x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    sf::Vector2f pos_orig0;
    pos_orig0 = points[pnt].getPosition();
    x1 = prev_x, y1 = prev_y, x2 = pos_orig0.x, y2 = pos_orig0.y;
    prev_x = (x1 + x2 * h) / (1 + h);
    prev_y = (y1 + y2 * h) / (1 + h);
    sf::CircleShape pp(0.5f);
    pp.setFillColor(sf::Color::Cyan);
    pp.setPosition(prev_x, prev_y);
    window->draw(pp);
    for (int i = 0; i < points_cnt; ++i) {
        window->draw(points[i]);
    }
}