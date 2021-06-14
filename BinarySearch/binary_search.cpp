#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int element){
    int start = 0;
    int end = n;
    
    while(start <= end){
    int mid = start + (end-start)/2;
        if(arr[mid]==element){
            return mid;
        }
        else if(arr[mid] < element){
            //search in second half
            start = mid+1;
        }
        else{
            // search in first half
            end = mid -1;
        }
    }
    return -1;
}

int main(){

    int arr[] = {23,38,48,51,56,82,99,1001};
    int n = sizeof(arr)/sizeof(arr[0]);
    int index = binarySearch(arr,n,99);
    cout<<"Found 99 at index "<<index<<endl;
    return 0;
}