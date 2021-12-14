#include "Point3D.cpp"
#include "src/include/SFML/Graphics/Drawable.hpp"
#include "src/include/SFML/Graphics/RenderWindow.hpp"
#include "src/include/SFML/Graphics/Vertex.hpp"
#include <iostream>

class Triangle{
    private:
        Point3D points[3];
        int translatedX = 0;
        int translatedY = 0;
    public:
        Triangle(Point3D a,Point3D b,Point3D c){
            points[0] = a;
            points[1] = b;
            points[2] = c;
        }

        void draws(sf::RenderTarget& target, sf::RenderStates states)
        {
            sf::Vertex line[4];
            line[0]= sf::Vertex(sf::Vector2f(points[0].x, points[0].y),sf::Color::White);
            line[1]= sf::Vertex(sf::Vector2f(points[1].x, points[1].y),sf::Color::White);
            line[2]= sf::Vertex(sf::Vector2f(points[2].x, points[2].y),sf::Color::White);
            line[3]= sf::Vertex(sf::Vector2f(points[0].x, points[0].y),sf::Color::White);
            target.draw(line, 4, sf::LineStrip, states);
        }

        void rotateX(int angle){
            points[0].rotateX(angle);
            points[1].rotateX(angle);
            points[2].rotateX(angle);
        }

        void rotateY(int angle){
            points[0].rotateY(angle);
            points[1].rotateY(angle);
            points[2].rotateY(angle);
        }

        void rotateZ(int angle){
            points[0].rotateZ(angle, translatedX, translatedY);
            points[1].rotateZ(angle, translatedX, translatedY);
            points[2].rotateZ(angle, translatedX, translatedY);
        }

        void selfRotateX(int angle){
            points[0].rotateX(angle, translatedX, translatedY);
            points[1].rotateX(angle, translatedX, translatedY);
            points[2].rotateX(angle, translatedX, translatedY);
        }

        void selfRotateY(int angle){
            points[0].rotateY(angle, translatedX, translatedY);
            points[1].rotateY(angle, translatedX, translatedY);
            points[2].rotateY(angle, translatedX, translatedY);
        }

        void selfRotateZ(int angle){
            points[0].rotateZ(angle, translatedX, translatedY);
            points[1].rotateZ(angle, translatedX, translatedY);
            points[2].rotateZ(angle, translatedX, translatedY);
        }

        void translate(int dx, int dy){
            translatedX = dx;
            translatedY = dy;
            points[0].translate(dx,dy);
            points[1].translate(dx,dy);
            points[2].translate(dx,dy);
        }

        void resize(int n){
            points[0].resize(n);
            points[1].resize(n);
            points[2].resize(n);
        }

        void showPoints(){
            cout<< "========"<<endl;
            points[0].printCoord();
            points[1].printCoord();
            points[2].printCoord();
        }
};