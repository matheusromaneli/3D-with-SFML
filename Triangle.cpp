#include "Point3D.cpp"
#include "src/include/SFML/Graphics/Drawable.hpp"
#include "src/include/SFML/Graphics/RenderWindow.hpp"
#include "src/include/SFML/Graphics/Vertex.hpp"
#include <iostream>

class Triangle{
    private:
        Point3D* points[3];
        int translatedX = 0;
        int translatedY = 0;
    public:
        Triangle(Point3D* a,Point3D* b,Point3D* c){
            points[0] = a;
            points[1] = b;
            points[2] = c;
        }

        void draws(sf::RenderTarget& target, sf::RenderStates states)
        {
            Point3D l1(points[1]->x - points[0]->x, points[1]->y - points[0]->y, points[1]->z - points[0]->z);
            Point3D l2(points[2]->x - points[0]->x, points[2]->y - points[0]->y, points[2]->z - points[0]->z);
            Point3D normal(l1.y*l2.z - l2.y*l1.z, l1.z*l2.x - l2.z*l1.x, l1.x*l2.y - l2.x*l1.y);
            // Point3D cam(400,300,300);
            int color_value = (int)(-normal.z)%255;
            sf::Color c(color_value, color_value, color_value);
            // if(normal.z >0){
                sf::Vertex line[4];
                line[0]= sf::Vertex(sf::Vector2f(points[0]->x, points[0]->y),c);
                line[1]= sf::Vertex(sf::Vector2f(points[1]->x, points[1]->y),c);
                line[2]= sf::Vertex(sf::Vector2f(points[2]->x, points[2]->y),c);
                line[3]= sf::Vertex(sf::Vector2f(points[0]->x, points[0]->y),c);
                target.draw(line, 4, sf::LinesStrip, states);
            // }
        }

        void rotateX(int angle){
            points[0]->rotateX(angle);
            points[1]->rotateX(angle);
            points[2]->rotateX(angle);
        }

        void rotateY(int angle){
            points[0]->rotateY(angle);
            points[1]->rotateY(angle);
            points[2]->rotateY(angle);
        }

        void rotateZ(int angle){
            points[0]->rotateZ(angle);
            points[1]->rotateZ(angle);
            points[2]->rotateZ(angle);
        }

        void selfRotateX(int angle){
            points[0]->selfRotateX(angle);
            points[1]->selfRotateX(angle);
            points[2]->selfRotateX(angle);
        }

        void selfRotateY(int angle){
            points[0]->selfRotateY(angle);
            points[1]->selfRotateY(angle);
            points[2]->selfRotateY(angle);
        }

        void selfRotateZ(int angle){
            points[0]->selfRotateZ(angle);
            points[1]->selfRotateZ(angle);
            points[2]->selfRotateZ(angle);
        }

        void translate(int dx, int dy){
            translatedX = dx;
            translatedY = dy;
            points[0]->translate(dx,dy);
            points[1]->translate(dx,dy);
            points[2]->translate(dx,dy);
        }

        void resize(int n){
            points[0]->resize(n);
            points[1]->resize(n);
            points[2]->resize(n);
        }

        void showPoints(){
            cout<< "========"<<endl;
            points[0]->printCoord();
            points[1]->printCoord();
            points[2]->printCoord();
        }
};