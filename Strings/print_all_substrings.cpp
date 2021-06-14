#include <iostream>
#include <string>
using namespace std;


int main(){
    string s = "abcd";
    int n = s.size();
    int size = (n*(n+1))/2;
    int arr[size];
    int k = 0;

    for(int len=1; len<=n; len++){
        for(int i=0; i<=n-len; i++){
            int j = i+len-1;
            for(int k=i; k<=j; k++)
                cout<<s[k];
            cout<<"\n";
        }
    }

}