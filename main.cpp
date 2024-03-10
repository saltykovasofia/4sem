#include "Square.h"
#include "Triangle.h"
#include "Circle.h"
#include <iostream>
#include "TriangularPiramid.h"
#include "Cylinder.h"
#include "Sphere.h"



void test_2d(Square& s,Triangle& t, Circle& c){

    s.ShowInfo();
    s.CalculateArea();
    s.ShowInfo();
    s.Scale(2);
    s.ShowInfo();

    t.CalculateArea();
    t.ShowInfo();

    c.CalculateArea();
    c.ShowInfo();
    if(t>s)std::cout<<"t>s"<<std::endl;
    else if(t<s)std::cout<<"t<s"<<std::endl;
    else std::cout<<"t==s"<<std::endl;
    t.Scale(20);
    t.ShowInfo();
    if(t>s)std::cout<<"t>s"<<std::endl;
    else if(t<s)std::cout<<"t<s"<<std::endl;
    else std::cout<<"t==s"<<std::endl;
}

void test_3d(TriangularPiramid& tp , Cylinder& cyl , Sphere& s){
    tp.ShowInfo();
    tp.CalculateVolume();
    tp.ShowInfo();
    tp.Scale(2);
    tp.ShowInfo();

    cyl.ShowInfo();
    cyl.CalculateVolume();
    cyl.ShowInfo();
    cyl.Scale(3);
    cyl.ShowInfo();

    if(tp>cyl)std::cout<<"tp>cyl"<<std::endl;
    else if(tp<cyl)std::cout<<"tp<cyl"<<std::endl;
    else std::cout<<"tp==cyl"<<std::endl;

    s.ShowInfo();
    s.CalculateVolume();
    s.ShowInfo();
    s.Scale(4);
    s.ShowInfo();

    if(tp>s)std::cout<<"tp>s"<<std::endl;
    else if(tp<s)std::cout<<"tp<s"<<std::endl;
    else std::cout<<"tp==s"<<std::endl;
}



int main(){
    // Shape2D ;
    Square sq1(10);
    Triangle tr1(10,2);
    Circle c1(5);

    test_2d(sq1,tr1,c1);

    // Shape3D 
    TriangularPiramid trp1(5,tr1);
    Cylinder cyl1(6,c1);
    Sphere s1(10);

    test_3d(trp1,cyl1,s1);

}
