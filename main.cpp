#include "src/include/SFML/Graphics.hpp"
#include "src/include/SFML/System/Vector2.hpp"
#include "Mesh.cpp"
#include <iostream>
using namespace std;
// g++ -Isrc/include -c main.cpp && g++ main.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system && main.exe
int main(int argc, char const *argv[])
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    Mesh plano;
    plano.readFrom("craneo2.obj");
    plano.resize(300);
    plano.translate(400,300);
    int dr = 2;
    sf::Vector2i mouse;
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        sf::Vector2i last = mouse;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                plano.rotateY(-dr);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                plano.rotateY(dr);
            }
            // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            //     plano.resize(size);
            // }
            // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !(size - 10 < 1)){
            //     plano.resize(size);
            // }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                plano.selfRotateY(-dr);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                plano.selfRotateY(dr);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
                plano.selfRotateX(1);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
                plano.selfRotateX(-1);
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                sf::Vector2i last = mouse;
                mouse = sf::Mouse::getPosition();
                int dx = mouse.x - last.x;
                int dy = mouse.y - last.y;
                plano.selfRotateY(dx);
                plano.selfRotateX(dy);
            }
        }

        // clear the window with black color
        window.clear(sf::Color::Black);
        // draw everything here...
        // window.draw(...);
        window.draw(plano);

        // end the current frame
        window.display();
    }
    return 0;
}
