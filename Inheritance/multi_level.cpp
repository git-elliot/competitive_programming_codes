#include<iostream>
using namespace std;

//Multilevel inheritance is a process of deriving a class from another derived class.

class Rectangle{
    public: 
    int length = 10;
    int breadth = 20;
    int area(){
        return length*breadth;
    }
};
class CardBoard : public Rectangle{
    public:
    int costPerSquareMeter = 10;
    int price(){
        return costPerSquareMeter*area();
    }
};

class Box : public CardBoard{
    public:
    int height = 30;
    int volume(){
        return area()*height;
    }
    int surfaceArea(){
        return 2*(length*breadth + breadth*height + length*height);
    }
    int cost(){
        return costPerSquareMeter*surfaceArea();
    }
};
int main(){
    Box box;
    cout<<"L, B, H : "<<box.length<<", "<<box.breadth<<", "<<box.height<<endl;
    cout<<"Volume : "<<box.volume()<<" cubic meter"<<endl;
    cout<<"Cost of Box: "<<box.cost()<<" Rs"<<endl;
}