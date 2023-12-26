// Copyright 2023 Bikash Shrestha
#include "hexa.hpp"

// initialize the Hexaflake with size L and depth N
Hexaflake::Hexaflake(double L, int N) : L(L), N(N) {}

// draw the main Hexaflake centered on the screen
void Hexaflake::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    drawHexaflake(target, states, target.getSize().x / 2.0,
    target.getSize().y / 2.0, L, N, sf::Color::Red);
}

// recursively draw the Hexaflake
void Hexaflake::drawHexaflake(sf::RenderTarget &target,
sf::RenderStates states, double x, double y, double sideLength, int depth, sf::Color color) const {
    // if depth is 0, draw a hexagon
    if (depth == 0) {
        sf::ConvexShape hexagon(6);
        for (int i = 0; i < 6; i++) {
            hexagon.setPoint(i, sf::Vector2f(x + sideLength * cos(i * M_PI / 3),
            y + sideLength * sin(i * M_PI / 3)));
        }
        hexagon.setFillColor(color);
        target.draw(hexagon, states);
        return;
    }

    // set the next color
    sf::Color nextColor;
    if (color == sf::Color::Red)
        nextColor = sf::Color::Green;
    else if (color == sf::Color::Green)
        nextColor = sf::Color::Yellow;
    else
        nextColor = sf::Color::Red;

    // draw smaller hexaflakes around the current one
    for (int i = 0; i < 6; i++) {
        double nextX = x + (sideLength * cos(i * M_PI / 3));
        double nextY = y + (sideLength * sin(i * M_PI / 3));
        drawHexaflake(target, states, nextX, nextY, sideLength / 3, depth - 1, nextColor);
    }
    // draw smaller hexaflake at the center
    drawHexaflake(target, states, x, y, sideLength / 3, depth - 1, color);
}
