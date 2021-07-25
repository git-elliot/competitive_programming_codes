#include<iostream>
using namespace std;
//Hierarchical inheritance is defined as the process of deriving more than one class from a base class.
class Shape{
    public:
    int a = 10;
    int b = 20;
};

class Rectange : public Shape{
    public:
    int area(){
        return a*b;
    }
};

class Triangle : public Shape{
    public:
    float area(){
        return 0.5*a*b;
    }
};

int main(){
    Rectange rect;
    cout<<"Area of Rect: "<<rect.area()<<endl;
    Triangle tri;
    cout<<"Area of Triangle: "<<tri.area()<<endl;
}