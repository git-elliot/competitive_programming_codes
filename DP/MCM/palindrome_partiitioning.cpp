#include<iostream>
using namespace std;

bool isPallindrome(string &s, int i, int j, vector<vector<int>> &p){
        if(i>j) return 1;
        if(i==j) return p[i][j] = 1;
        if(p[i][j]!=-1) return p[i][j];
        if(s[i]!=s[j]) return p[i][j] = 0;
        p[i][j] = isPallindrome(s,i+1,j-1,p);
        return p[i][j];
    }
   
    int pallindromePartitioningMCM(string &s, int i, int j, vector<vector<int>> &t,
    vector<vector<int>> &p){
       
        if(i>=j) return 0;
        
        if(t[i][j]!=-1) 
            return t[i][j];
        
        if(p[i][j]==1) 
            return t[i][j] = 0;
        
        int mn = INT_MAX;
        for(int k=i; k<j; k++)
            if(p[i][k])
                mn = min(mn,pallindromePartitioningMCM(s,i,k,t,p)
                +pallindromePartitioningMCM(s,k+1,j,t,p)+1);
            
        return t[i][j] = mn;
    }

    int pallindromePartitioning(string s) {
       int n = s.size();
       vector<vector<int>> t(n,vector<int>(n,-1));
       vector<vector<int>>  p(n,vector<int>(n,-1));
       for(int i=0; i<n; i++)
            for(int j=i; j<n; j++)
                isPallindrome(s,i,j,p);
        
        return solve(s,0,n-1,t,p);
    }
   
   
int main(){
    //132. Palindrome Partitioning II
    //https://leetcode.com/problems/palindrome-partitioning-ii/
    cout<<"Min. Cut Pallindrome Partitiong: "<<pallindromePartitioning("ab")<<endl;
}