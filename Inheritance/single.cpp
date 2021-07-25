#include<iostream>

using namespace std;
//Single inheritance is defined as the inheritance in which a derived class is inherited from the only one base class.
class Account{
    public: 
    int balance = 1000;
};

class Programmer : public Account{
    public:
    float bonus = 500.0;
};
class User : private Account{
    public:
    float loan = 1000.0;
    void showBalance(){
        cout<<"Balance: "<<balance<<endl;
    }
};

int main(){
    Programmer p;
    cout<<"Balance: "<<p.balance<<endl;
    cout<<"Bonus: "<<p.bonus<<endl;

    User u;
    u.showBalance();
    cout<<"Loan: "<<u.loan<<endl;

}