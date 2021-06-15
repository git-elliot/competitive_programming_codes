#include<iostream>
#include<vector>
using namespace std;

int eggDrop(int e, int f, vector<vector<int> > &t){
    if(f<=1) return f;
    if(e==1) return f;
    if(t[e][f]!=-1) return t[e][f];
    int mn = INT_MAX;
    for(int k = 1; k<=f; k++){
        int temp = 1 +  max(eggDrop(e-1,k-1,t),eggDrop(e,f-k,t));
        mn = min(mn,temp);
    }
    return t[e][f] = mn;
}

int main(){
    int e = 3, f= 5;
    vector<vector<int> > t(e+1,vector<int>(f+1,-1));
    cout<<"Attempts: "<<eggDrop(e,f,t)<<endl;
}