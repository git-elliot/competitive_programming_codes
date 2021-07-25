#include<iostream>
using namespace std;
int t[1001][1001][2];

    int solve(string &s, int i, int j, int isTrue){
        if(i>j) return 0;
        if(i==j) return isTrue? s[i] =='T' : s[i] == 'F';
        if(t[i][j][isTrue]!=-1) return t[i][j][isTrue];
        int ans = 0;
        for(int k=i+1; k<j; k+=2){
            int lt = t[i][k-1][1]!=-1 ? t[i][k-1][1] : solve(s,i,k-1,1); 
            int lf = t[i][k-1][0]!=-1 ? t[i][k-1][0] : solve(s,i,k-1,0); 
            int rt = t[k+1][j][1]!=-1 ? t[k+1][j][1] : solve(s,k+1,j,1);
            int rf = t[k+1][j][0]!=-1 ? t[k+1][j][0] : solve(s,k+1,j,0); 
            switch(s[k]){
                case '|' : isTrue? (ans+= lt*rf+ lf*rt + lt*rt) : (ans+= lf*rf);
                            break;
                case '&' : isTrue? (ans+= lt*rt) : (ans+= lt*rf+ lf*rt + lf*rf);
                            break;
                case '^' : isTrue? (ans+= lt*rf+ lf*rt ) : (ans+= lt*rt + lf*rf);
                            break;
            }
        }
        return t[i][j][isTrue]= ans % 1003;
    }
    int countWays(int N, string S){
        memset(t,-1,sizeof(t));
        return solve(S,0,S.size()-1,true) ;
    }
    
int main(){
    string s= "F|T^T&F";
    cout<<"Ways to Parenthesize: "<<countWays(s.size(),s)<<endl;

}