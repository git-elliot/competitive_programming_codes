#include <iostream>
#include <unordered_map>
using namespace std;

int main(){

    unordered_map<string,int> umap;
    umap["something"] = 10;
    umap["anything"] = 29;
    umap["anyone"] = 282;

    for(auto it : umap){
        cout<<"Key : "<<it.first<<" value : "<<it.second<< endl;
    }
    return 0;
}