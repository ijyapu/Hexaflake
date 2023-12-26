// Copyright 2023 Bikash SHrestha
#include <cmath>
#include <SFML/Graphics.hpp>


class Hexaflake : public sf::Drawable {
 public:
    Hexaflake(double L, int N);  // constructor with size L and depth N
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

 private:
    double L;    // hexagon's side length
    int N;      // fractal depth
    void drawHexaflake(sf::RenderTarget &target, sf::RenderStates states, double x, double y,
    double sideLength, int depth, sf::Color color) const;
};
