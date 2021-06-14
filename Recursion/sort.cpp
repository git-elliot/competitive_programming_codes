#include <iostream>
#include <vector>
using namespace std;

void myInsert(vector<int> &v, int temp){
    if(v.size()==0 || v[v.size()-1]<=temp){
        v.push_back(temp);
        return;
    }
    int val = v[v.size()-1];
    v.pop_back();
    myInsert(v,temp);
    v.push_back(val);
    return;
}

void mySort(vector<int> &v){
    if(v.size()==1){
        return;
    }
    int temp = v[v.size()-1];
    v.pop_back();
    mySort(v);
    myInsert(v,temp);
}

int main(){
    vector<int> inp{1,4,0,9,8,3};
    mySort(inp);
    for(int x : inp) cout<<x<<" ";
    cout<<endl;
    return 1;
}