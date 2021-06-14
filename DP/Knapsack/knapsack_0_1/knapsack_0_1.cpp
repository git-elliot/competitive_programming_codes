#include<iostream>
#include <cstring>

using namespace std;

int t[1000][1000];
int knapsackTopDown(int wt[],int val[], int w, int n){
    memset(t,-1,sizeof(t));
    for(int i=1; i<n+1; i++)//filling first column
        for(int j=0; j<w+1; j++)//filling first row
          if(i==0 || j ==0) 
            t[i][j]=0;

    for(int i=1; i<n+1; i++)
        for(int j=1; j<w+1; j++)
            if(wt[i-1]<=j)
                t[i][j] = max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
            else
                t[i][j] = t[i-1][j];

    return t[n][w];
}

int solveKnapsackBottomUp(int wt[],int val[], int w, int n){
    if(n==0|| w==0) return 0;
    if(t[n][w]!=-1) return t[n][w];

    if(wt[n-1]<=w)
        return t[n][w] = max(
            val[n-1]+ solveKnapsackBottomUp(wt,val,w-wt[n-1],n-1), 
            solveKnapsackBottomUp(wt,val,w,n-1)
        );
    return t[n][w] = solveKnapsackBottomUp(wt,val,w,n-1);
}

int knapsackBottomUp(int wt[],int val[], int w, int n){
    memset(t,-1,sizeof(t));
    solveKnapsackBottomUp(wt,val,w,n);
    return t[n][w];
}

int main(){
    int wt[] = {1,3,4,5};
    int val[] = {1,4,5,7};
    int C = 7;

    cout<< "Bottom UP: " << knapsackBottomUp(wt,val,C,sizeof(wt)/sizeof(wt[0]));
    cout<< "\nTop Down: " << knapsackTopDown(wt,val,C,sizeof(wt)/sizeof(wt[0]));
    cout<<endl;
    return 0;
}