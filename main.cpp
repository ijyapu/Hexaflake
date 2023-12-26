// Copyright 2023 Bikash Shrestha
#include <iostream>
#include "hexa.hpp"
#include <SFML/Graphics.hpp>

int main(int argc, char **argv) {
    // check for correct number of command-line arguments
    if (argc != 3) {
        std::cerr << "Usage: ./Hexa L N" << std::endl;
        return -1;
    }

    double L = std::stod(argv[1]);  // side length
    int N = std::stoi(argv[2]);     // depth

    // create a window
    sf::RenderWindow window(sf::VideoMode(800, 800), "Hexaflake");
    Hexaflake hexaflake(L, N);

    // main rendering loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // draw the Hexaflake and display
        window.clear();
        window.draw(hexaflake);
        window.display();
    }

    return 0;
}
