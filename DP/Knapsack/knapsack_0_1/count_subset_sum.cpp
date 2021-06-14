#include<iostream>
#include<cstring>

using namespace std;

int t[1000][1000];
//Problem 3
int countSubsetSum(int nums[], int sum, int n){
    int i,j;
    memset(t,-1,sizeof(t));
    for(i=0; i<n+1; i++){
        for( j=0; j<sum+1; j++){
            if(i==0) t[i][j] = 0;
            if(j==0) t[i][j] = 1;
        }
    }

    for(i=1; i<n+1; i++){
        for(j=1; j<sum+1; j++){
            if(nums[i-1]<=j)
                t[i][j] = t[i-1][j-nums[i-1]] + t[i-1][j];
            else 
                t[i][j] = t[i-1][j];
        }
    }
    return t[n][sum];
}
//Problem 5
int countSubsetSumWithDiff(int nums[], int diff, int n){
    //s1 + s2 = sum(arr)        -- (1)
    //s1 - s2 = diff            -- (2)
    //2s1 = diff + sum(arr)     -- (1)+(2)
    //s1 = (diff + sum(arr))/2  -- rearrange

    int s = 0;
    for(int i=0; i<n; i++) s+=nums[i];

    int sum = (s + diff)/2;
    return countSubsetSum(nums, sum, n);
}

int targetSum(int nums[], int sum, int n){
    return countSubsetSum(nums, sum, n);
}

int main(){
    int nums[] = {1, 5, 11, 5};
    int sum = 6, diff = 1;

    cout<<"Subset Sum result : "<<countSubsetSum(nums, sum, sizeof(nums)/sizeof(nums[0]));
    cout<<"\nSubset Sum with diff result : "<<countSubsetSumWithDiff(nums, diff, sizeof(nums)/sizeof(nums[0]));
    cout<<"\nTarget Sum result : "<<countSubsetSum(nums, sum, sizeof(nums)/sizeof(nums[0]));
    
    cout<<endl;
    return 0;
}