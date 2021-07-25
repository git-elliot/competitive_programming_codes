#include<iostream>
using namespace std;
//Multiple inheritance is the process of deriving a new class that inherits the attributes from two or more classes.
class A{
    public: 
    void display(){
        cout<<"A";
    }
};

class B{
    public: 
    void display(){
        cout<<"B";
    }
};

class C : public A, B{
    public: 
    void view(){
        // display(); ambigous call to display()
        A::display(); //Resolve ambiguity using class resolution operator
        B::display();
    }
};
