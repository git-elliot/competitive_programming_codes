#include<iostream>
#include <cstring>

using namespace std;

int t[1000][1000];
int unboundedKnapsackTopDown(int wt[],int val[], int w, int n){
    // or Rod cutting problem

    memset(t,-1,sizeof(t));
    for(int i=1; i<n+1; i++)//filling first column
        for(int j=0; j<w+1; j++)//filling first row
          if(i==0 || j ==0) 
            t[i][j]=0;

    for(int i=1; i<n+1; i++)
        for(int j=1; j<w+1; j++)
            if(wt[i-1]<=j)
                t[i][j] = max(val[i-1]+t[i][j-wt[i-1]], // i is passed to t when including answer, multiple occurences allowed
                t[i-1][j]);
            else
                t[i][j] = t[i-1][j];

    return t[n][w];
}

int solveUnboundedKnapsackBottomUp(int wt[],int val[], int w, int n){
    if(n==0|| w==0) return 0;
    if(t[n][w]!=-1) return t[n][w];

    if(wt[n-1]<=w)
        return t[n][w] = max(
            val[n-1]+ solveUnboundedKnapsackBottomUp(wt,val,w-wt[n-1],n), // n is passed again when including answer, multiple occurences allowed
            solveUnboundedKnapsackBottomUp(wt,val,w,n-1)
        );
    return t[n][w] = solveUnboundedKnapsackBottomUp(wt,val,w,n-1);
}

int unboundedKnapsackBottomUp(int wt[],int val[], int w, int n){
    memset(t,-1,sizeof(t));
    solveUnboundedKnapsackBottomUp(wt,val,w,n);
    return t[n][w];
}

long long int coinChangeFirst(int coin[], int sum, int n){
    //max number of ways
    int m = n;
    int n = sum;
    long long t[n+1][m+1];
       
       for(int i=1; i<m+1; i++){
           t[0][i] = 0;   
       }
       
       for(int i=0; i<n+1; i++){
           t[i][0] = 1;
       }
       
       for(int i=1; i<n+1; i++){
           for(int j=1; j < m+1; j++){
               if(S[i-1] <= j){
                   t[i][j] = t[i-1][j]+t[i][j-S[i-1]];
               }
               else{
                   t[i][j] = t[i-1][j];
               }
           }
       }
       return t[n][m];
}

int coinChangeSecond(int coin[], int sum, int n){
    //min. number of coins
    memset(t,-1,sizeof(t));
    for(int i=1; i<n+1; i++){
        for(int j=0; j<sum+1; j++){
            if(j==0) t[i][j]=0;
            if(i==0) t[i][j]=INT_MAX-1;
        }
    }
    for(int j=1; j<sum+1; j++){
        if(j%coin[0]==0){
            t[1][j]= j/coin[0];
        }else{
            t[1][j] = INT_MAX-1;
        }
    }
        

    for(int i=2; i<n+1; i++)
        for(int j=1; j<sum+1; j++)
            if(coin[i-1]<=j)
                t[i][j] = min(t[i][j-coin[i-1]]+1, // i is passed to t when including answer, multiple occurences allowed
                t[i-1][j]);
            else
                t[i][j] = t[i-1][j];
                
    if(t[n][sum]==INT_MAX-1) return -1;
    return t[n][sum];
}


int main(){
    int wt[] = {1,3,4,5};
    int val[] = {1,4,5,7};
    int C = 7;

    cout<< "Bottom UP: " << unboundedKnapsackBottomUp(wt,val,C,sizeof(wt)/sizeof(wt[0]));
    cout<< "\nTop Down: " << unboundedKnapsackTopDown(wt,val,C,sizeof(wt)/sizeof(wt[0]));

    int coin[] = {1,2,3};
    int sum = 5;
    cout<< "\nCoin Change II: " << coinChangeSecond(coin,sum,sizeof(coin)/sizeof(coin[0]));
    cout<<endl;
    return 0;
}