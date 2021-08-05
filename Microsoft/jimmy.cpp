#include<iostream>
#include<vector>
// #define UP(vector<int> arr,j)
using namespace std;
bool check(vector<int> arr){
      bool check = false;
      for (int j = 0; j < arr.size()-2 ; j++) {
        if ((arr[j] - arr[j + 1] > 0) && (arr[j + 1] - arr[j + 2] < 0)) {
            check = true;
        } else if ((arr[j] - arr[j + 1] < 0) && (arr[j + 1] - arr[j + 2] > 0)) {
            check = true;
        } else {
            check = false;
            break;
        }
    }
    return check;
}
int solution(vector<int> A){
    int count = 0;
    if (check(A)) {
        return 0;
    }
    for (int i = 0; i < A.size(); i++) {
        vector<int> ab(A);
        ab.erase(ab.begin()+i);
        if (check(ab)) {
            count++;
        }
    }
    if (count == 0)
        count = -1;

    return count;
}

int main(){
    vector<int> arr1 = {2,3,5,4};
    cout<<solution(arr1)<<endl;
    vector<int> arr2 = {2,3,4,5};
    cout<<solution(arr2)<<endl;
    vector<int> arr3 = {5,4,4,1,2,1};
    cout<<solution(arr3)<<endl;
    vector<int> arr4 = {5,4,5,1,2,1};
    cout<<solution(arr4)<<endl;
    cout<<"\n";
    vector<int> arr5 = { 3, 4, 5, 3, 7 };  
    cout<<solution(arr5)<<endl;
    vector<int> arr6 = { 1, 2, 3, 4 };   
    cout<<solution(arr6)<<endl;
    vector<int> arr7 = { 1, 3, 1, 2 }; //
    cout<<solution(arr7)<<endl;
    vector<int> arr9 = { 5, 3, 7, 8, 9 };
    cout<<solution(arr9)<<endl;
    

}
//mkdir -p .output && g++ -std=c++11 jimmy.cpp -o .output/jimmy.o && ./.output/jimmy.o