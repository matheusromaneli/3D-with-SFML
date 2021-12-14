#define _USE_MATH_DEFINES 
#include <cmath>
#include <iostream>

using namespace std;
class Point3D{
  public:
    double x,y,z;

    Point3D(){
      x=0;y=0;z=0;
    }

    Point3D(double dx, double dy, double dz){
      x = dx;
      y = dy;
      z = dz;
    }

    void rotateX(int angle){
      double rad = M_PI * angle/180;
      double aux_y =  cos(rad) * y + sin(rad) * z;
      double aux_z = -sin(rad) * y + cos(rad) * z;
      y = aux_y;
      z = aux_z;
    }

    void rotateY(int angle){
      double rad = M_PI * angle/180;
      double aux_x =  cos(rad) * x + sin(rad) * z;
      double aux_z = -sin(rad) * x + cos(rad) * z;
      x = aux_x;
      z = aux_z;
    }

    void rotateZ(int angle){
      double rad = M_PI * angle/180;
      double aux_x =  cos(rad) * x + sin(rad) * y;
      double aux_y = -sin(rad) * x + cos(rad) * y;
      x = aux_x;
      y = aux_y;
    }

    void rotateX(int angle, int dx, int dy){
      x -= dx;
      y -= dy;
      double rad = M_PI * angle/180;
      double aux_y =  cos(rad) * y + sin(rad) * z;
      double aux_z = -sin(rad) * y + cos(rad) * z;
      y = aux_y;
      z = aux_z;
      x += dx;
      y += dy;
    }

    void rotateY(int angle, int dx, int dy){
      x -= dx;
      y -= dy;
      double rad = M_PI * angle/180;
      double aux_x =  cos(rad) * x + sin(rad) * z;
      double aux_z = -sin(rad) * x + cos(rad) * z;
      x = aux_x;
      z = aux_z;
      x += dx;
      y += dy;
    }

    void rotateZ(int angle, int dx, int dy){
      x -= dx;
      y -= dy;
      double rad = M_PI * angle/180;
      double aux_x =  cos(rad) * x + sin(rad) * y;
      double aux_y = -sin(rad) * x + cos(rad) * y;
      x = aux_x;
      y = aux_y;
      x += dx;
      y += dy;
    }

    void translate(int dx, int dy){
      x += dx;
      y += dy;
    }

    void resize(int n){
      x = x*n;
      y = y*n;
      z = z*n;
    }

    void printCoord(){
      cout <<"x: "<< x <<" y: " << y <<" z: " << z << endl;
    }
};