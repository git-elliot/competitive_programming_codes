#include<iostream>
#include<algorithm>

using namespace std;

int minSteps(int arr[], int n){
    sort(arr,arr+n);
    int ans = 0, j = 0;
    for(int i=1; i<n; i++){
        if(arr[i-1]!=arr[i]){
            ans+= i;
        }
    }
    return ans;
}
int main(){
    // int arr[] = {1, 1, 2, 2, 2, 3, 3, 3, 4, 4};
    int arr[] = {5, 2, 1};
    cout<<minSteps(arr, (sizeof(arr)/sizeof(arr[0])))<<endl;
}
//mkdir -p .output && g++ -std=c++11 Min_Steps_to_Make_Piles_Equal_Height.cpp -o .output/Min_Steps_to_Make_Piles_Equal_Height.o && ./.output/Min_Steps_to_Make_Piles_Equal_Height.o