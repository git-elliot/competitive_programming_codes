#include <iostream>

using namespace std;

int firstOccurrence(int arr[],int n, int element){
    int result = -1;
    int start = 0;
    int end = n;
    while(start <= end){
        int mid = start + (end-start)/2;
        if(arr[mid]==element){
            result = mid;
            end = mid-1;
        }
        else if(arr[mid] < element){
            start = mid+1;
        }
        else{
            end = mid -1;
        }
    }
    return result;
}

int lastOccurence(int arr[],int n, int element){
    int result = -1;
    int start = 0;
    int end = n;
    while(start <= end){
        int mid = start + (end-start)/2;
        if(arr[mid]==element){
            result = mid;
            start = mid+1;
        }
        else if(arr[mid] < element){
            start = mid+1;
        }
        else{
            end = mid -1;
        }
    }
    return result;
}

int count(int arr[], int n, int element){
    int lower = firstOccurrence(arr,n,element);
    if(lower==-1){
        return 0;
    }

    int upper = lastOccurence(arr,n,element);
    return upper-lower+1;
}


int main(){

    
    int arr[] = {1,2,2,2,3,4,5,5,5,5,23,25,25,25};
    int n = sizeof(arr)/sizeof(arr[0]);
    int element;
    cout<<"Enter your element : ";
    cin>>element;
    int lower = firstOccurrence(arr,n,element);
    int upper = lastOccurence(arr,n,element);
    cout<<element<<"'s first occurence is : "<<lower<<endl;
    cout<<element<<"'s last occurence is : "<<upper<<endl;
    cout<<element<<"'s count is : "<<count(arr,n,element)<<endl;
    return 0;
}