#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

bool t[1000][1000];
//Problem 1
bool subsetSum(int nums[], int sum, int n){
    int i,j;
    memset(t,-1,sizeof(t));
    for(i=0; i<n+1; i++){
        for( j=0; j<sum+1; j++){
            if(i==0) t[i][j] = false;
            if(j==0) t[i][j] = true;
        }
    }

    for(i=1; i<n+1; i++){
        for(j=1; j<sum+1; j++){
            if(nums[i-1]<=j)
                t[i][j] = t[i-1][j-nums[i-1]] || t[i-1][j];
            else 
                t[i][j] = t[i-1][j];
        }
    }
    return t[n][sum];
}
//Problem 2 
bool equalSumPartition(int nums[], int n){
    int sum = 0;
    for(int i=0; i<n; i++) sum+=nums[i];
    if(sum%2!=0) return false;
    return subsetSum(nums, sum/2, n);
}

//Problem 4
int minSubsetSumDiff(int nums[], int n){
    int range = 0, mn = INT_MAX;
    vector<int> v;
    for(int i=0; i<n; i++) range+=nums[i]; //calculating valid subset sum values/candidates
    int sum = (range/2) + 1; //We only need half part because of s1 + s2 = range, so s2 = range - s1.
    subsetSum(nums,sum,n); // this will fill last row of table t i.e., t[n][i], where i is from 0 to sum.
    for(int i=0; i<sum; i++)
        if(t[n][i]) v.push_back(i); // Filter out valid sum values.
    
    for(int i=0; i<v.size(); i++)
        mn = min(mn, abs(range - 2*v[i])); // pick out minimum of them.
    return mn;
}

int main(){
    int nums[] = {1, 5, 11, 5};
    int sum = 6;
    cout<<"Subset Sum result : "<<subsetSum(nums, sum, sizeof(nums)/sizeof(nums[0]));
    cout<<"\nEqual Partition result : "<<equalSumPartition(nums, sizeof(nums)/sizeof(nums[0]));
    cout<<"\nMin SubsetSum diff result : "<<minSubsetSumDiff(nums, sizeof(nums)/sizeof(nums[0]));
    cout<<endl;
    return 0;
}