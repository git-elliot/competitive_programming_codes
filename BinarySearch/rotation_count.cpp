#include <iostream>
using namespace std;

int rotationCount(int arr[], int n){
    int start = 0;
    int end = n-1;
    
    if(arr[start] < arr[end]){
        return start;
    }

    while(start <= end){
        int mid = start + (end - start)/2;

        if(arr[mid-1] > arr[mid] < arr[mid+1]){
            return mid;
        }
        else if(arr[start] > arr[mid]){
            end = (mid+n-1)%n;
        }else {
            start = mid+1;
        }
    }
    return -1;
}

int main(){

    int arr[]= {11, 12, 13, 14, 2, 3, 4, 5, 6};
    cout<<"rotation count is : "<<rotationCount(arr,sizeof(arr)/sizeof(arr[0]))<<endl;
    return 0;
}