#include<iostream>
using namespace std;
//Hybrid inheritance is a combination of more than one type of inheritance.
class A{
    protected:
    int a;
    public:
    void get_a(){
        cout<<"Enter the value of a : ";
        cin>>a;
    }
};

class B : public A{
    protected:
    int b;
    public:
    void get_b(){
        cout<<"Enter the value of b : ";
        cin>>b;
    }
};

class C{
    protected:
    int c;
    public:
    void get_c(){
        cout<<"Enter the value of c : ";
        cin>>c;
    }
};

class D : public C, B{
    public:
    void mul(){
        get_a();
        get_b();
        get_c();
        cout<<"Multiplication of a,b,c : "<<a*b*c<<endl;
    }
};

int main(){
    D d;
    d.mul();
}