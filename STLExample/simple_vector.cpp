#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main(){
    int arr[] = {102,283,84,382,293,32,32,23};
    int n = sizeof(arr)/sizeof(arr[0]);

    vector<int> vect(arr,arr+n);
    cout<<"\nVector is : ";
    for (int i=0;i<n;i++)
        cout<<vect[i]<<" ";

    sort(vect.begin(),vect.end());

    cout<<"\nVector after sorting is : ";
    for (int i=0;i<n;i++)
        cout<<vect[i]<<" ";
  
    // reverse(vect.begin(),vect.end());

    // cout<<"\nVector after reversing is : ";
    // for (int i=0;i<n;i++)
    //     cout<<vect[i]<<" ";

    cout<<"\nMaximum element of vect is : ";
    cout<<*max_element(vect.begin(),vect.end());

    cout<<"\nMinimum element of vect is : ";
    cout<<*min_element(vect.begin(),vect.end());

    int upper = upper_bound(vect.begin(),vect.end(),84) - vect.begin();
    cout<<"\nUpper bound of 84 : "<<vect[upper];

    int lower = lower_bound(vect.begin(),vect.end(),84) - vect.begin();
    lower--;
    cout<<"\nUpper bound of 84 : "<<vect[lower]<<" at "<<lower;

    cout<<"\nAccumulation of v is : ";
    cout<<accumulate(vect.begin(),vect.end(),0); // initial value of sum is 0

    cout<<"\nOccurrences of 32 : ";
    cout<<count(vect.begin(), vect.end(),32);

    cout<<"\nFind of 32 : ";
    cout<<find(vect.begin(),vect.end(),302)-vect.begin();

    
    cout<<endl;
    
}