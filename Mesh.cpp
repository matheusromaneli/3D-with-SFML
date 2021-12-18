#include "Triangle.cpp"
#include "src/include/SFML/Graphics/Drawable.hpp"
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class Mesh: public sf::Drawable{
    private:
        Triangle* plane = NULL;
        Point3D* points = NULL;
        long int size_points = 0;
        int size_mesh = 0;
        int translateX = 0;
        int translateY = 0;
        int transform = 0;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            for(int i = 0; i < size_mesh; i++){
                plane[i].draws(target,states);
            }
        }

    public:
    
        void addTriangle(Point3D* a, Point3D* b, Point3D* c){
            size_mesh++;
            plane = (Triangle*)realloc(plane, sizeof(Triangle)*size_mesh);
            plane[size_mesh-1] = Triangle(a,b,c);
        }


        void rotateX(int angle){
            int i = 0;
            for(i = 0; i < size_points; i++){
                points[i].rotateX(angle);
            }
        }
        
        void rotateY(int angle){
            int i = 0;
            for(i = 0; i < size_points; i++){
                points[i].rotateY(angle);
            }
        }
        
        void rotateZ(int angle){
            int i = 0;
            for(i = 0; i < size_points; i++){
                points[i].rotateZ(angle);
            }
        }

        void selfRotateX(int angle){
            int i = 0;
            for(i = 0; i < size_points; i++){
                points[i].selfRotateX(angle);
            }
        }
        
        void selfRotateY(int angle){
            int i = 0;
            for(i = 0; i < size_points; i++){
                points[i].selfRotateY(angle);
            }
        }
        
        void selfRotateZ(int angle){
            int i = 0;
            for(i = 0; i < size_points; i++){
                points[i].selfRotateZ(angle);
            }
        }

        void translate(int dx, int dy){
            translateX = dx;
            translateY = dy;
            for(int i = 0; i < size_points; i++){
                points[i].translate(dx,dy);
            }
        }

        void resize(int n){
            for(int i = 0; i < size_points; i++){
                points[i].resize(n);
            }
        }

        void readFrom(const char* file){
            FILE* fe = fopen(file, "r");
            char type = 'v';
            float p1,p2,p3;
            for(int i =0; type != 'f'; i++){
                fscanf(fe, "%c %f %f %f\n", &type, &p1, &p2, &p3);
                if(type == 'v'){
                    size_points++;
                    points = (Point3D*) realloc(points, sizeof(Point3D)*size_points);
                    points[i] = Point3D(p1,p2,p3);
                } 
            }
            int l1 = (int)(p1);
            int l2 = (int)(p2);
            int l3 = (int)(p3);
            do{
                this->addTriangle(points+l1-1, points+l2-1, points+l3-1);
            }while(fscanf(fe,"%c %d %d %d\n", &type, &l1, &l2, &l3) != -1);
        }

};