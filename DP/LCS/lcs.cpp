#include<iostream>
#include<algorithm>
using namespace std;

int t[1001][1001]; // set according to constraints

int LCSBottomUP(string x, string y, int n, int m){
    if(n == 0 || m == 0) return 0;
    if(t[n][m]!=-1) return t[n][m];
    if(x[n-1]==y[m-1]) return t[n][m] = 1+LCSBottomUP(x,y,n-1,m-1);
    else return t[n][m] = max(LCSBottomUP(x,y,n-1,m),LCSBottomUP(x,y,n,m-1));
}

void LCSInit(int n, int m){
    for(int i=0; i<n+1; i++)
        for(int j=0; j<m+1; j++)
            if(i==0||j==0) t[i][j]=0;
}

int LCSTopDown(string x, string y, int n, int m){
    LCSInit(n,m);
    for(int i=1; i<n+1; i++)
        for(int j=1; j<m+1; j++)
            if(x[i-1]==y[j-1])
                t[i][j] = 1 + t[i-1][j-1];
            else 
                t[i][j] = max(t[i-1][j],t[i][j-1]);
    return t[n][m];
}

int LongestCommonSubstring(string x, string y, int n, int m){
    LCSInit(n,m);
    int ans = INT_MIN;
    for(int i=1; i<n+1; i++)
        for(int j=1; j<m+1; j++)
            if(x[i-1]==y[j-1])
                ans = max(t[i][j] = 1 + t[i-1][j-1],ans);
            else t[i][j] = 0;

    return ans;
}

string printLCS(string x, string y, int n, int m){
    LCSTopDown(x,y,n,n);
    int i=n, j=m; 
    string s = "";
    while(i>0 && j>0){
        if(x[i-1]==y[j-1]){
            s.push_back(x[i-1]);
            i--; j--;
        }
        else{
            if(t[i][j-1]>t[i-1][j]){
                j--;
            }
            else{
                i--;
            }
        }
    }

    reverse(s.begin(), s.end());
    return s;
}

int shortestCommonSupersequence(string x, string y, int n, int m){
     return n+m - LCSTopDown(x,y,n,m);
}
void minInsertionDeletion(string x, string y, int n, int m){
    int lcs = LCSTopDown(x,y,n,m);
    cout<<"4. Min. Deletions : "<<n - lcs<<", "<<"Min. Insertions : "<<m - lcs<<endl;
}
int longestPallindromicSubsequence(string x, int n){
    string y = x;
    reverse(y.begin(), y.end());    
    return LCSTopDown(x,y,n,n);
}
int minDeletionToMakePallindrome(string x, int n){
    return n - longestPallindromicSubsequence(x,n);
}

string printShortestCommonSupersequence(string x, string y, int n, int m){
    LCSTopDown(x,y,n,n);
    int i=n, j=m; 
    string s = "";
    while(i>0 && j>0){
        if(x[i-1]==y[j-1]){
            s.push_back(x[i-1]);
            i--; j--;
        }
        else{
            if(t[i][j-1]>t[i-1][j]){
                s.push_back(y[j-1]);
                j--;
            }
            else{
                s.push_back(x[i-1]);
                i--;
            }
        }
    }

    while(i>0){
        s.push_back(x[i-1]);
        i--;
    }

    while(j>0){
        s.push_back(y[j-1]);
        j--;
    }

    reverse(s.begin(), s.end());
    return s;
}

int longestRepeatingSubsequence(string x, string y, int n, int m){
    LCSInit(n,m);
    for(int i=1; i<n+1; i++)
        for(int j=1; j<m+1; j++)
            if(x[i-1]==y[j-1] && i!=j)
                t[i][j] = 1 + t[i-1][j-1];
            else 
                t[i][j] = max(t[i-1][j],t[i][j-1]);
    return t[n][m];
}

bool sequencePatternMatching(string x, string y, int n, int m){
    //is x a subsequence of y?
    return LCSTopDown(x,y,n,m) == n;
}

int main(){
    string x = "abcda", y = "abfca";
    memset(t,-1,sizeof(t));
    cout<<"1. LCS BU: "<<LCSBottomUP(x,y,x.length(), y.length())<<endl;
    cout<<"2. LCS TD: "<<LCSTopDown(x,y,x.length(), y.length())<<endl;
    cout<<"3. LCS print: "<<printLCS(x,y,x.length(), y.length())<<endl;
    minInsertionDeletion(x,y,x.length(), y.length());
    cout<<"5. LPS: "<<longestPallindromicSubsequence(x,x.length())<<endl; 
    cout<<"6. Min. Deletion to make pallindrome: "<<minDeletionToMakePallindrome(x,x.length())<<endl; 
    cout<<"7. SCS Print: "<<printShortestCommonSupersequence(x,y,x.length(), y.length())<<endl; 
    cout<<"8. LRS : "<<longestRepeatingSubsequence(x,y,x.length(), y.length())<<endl; 
    cout<<"9. Subsequence Pattern : "<<sequencePatternMatching(x,y,x.length(), y.length())<<endl; 
    cout<<"LC substring: "<<LongestCommonSubstring(x,y,x.length(), y.length())<<endl; 
    return 0;
}