#include <iostream>
#include <string.h>

using namespace std;

#define q 101
#define d 256

int naiveMatching(string text, string pattern){
    int n = text.size(), m = pattern.size();
    for(int i=0; i<n-m; i++){
        bool flag = true;
        for(int j=0; j<m; j++){
            if(pattern[j]!=text[i+j]){
                flag = false;
                break;
            }
        }
        if(flag) return i;
    }
    return -1;
}

int rabinKarp(string text, string pattern){
    // hash( txt[s+1 .. s+m] ) = ( d ( hash( txt[s .. s+m-1]) – txt[s]*h ) + txt[s + m] ) mod q 
    // hash( txt[s .. s+m-1] ) : Hash value at shift s. 
    // hash( txt[s+1 .. s+m] ) : Hash value at next shift (or shift s+1) 
    // d: Number of characters in the alphabet 
    // q: A prime number 
    // h: d^(m-1)

    // For example pattern length is 3 and string is “23456” 
    // You compute the value of first window (which is “234”) as 234. 
    // How how will you compute value of next window “345”? You will do (234 – 2*100)*10 + 5 and get 345.

    int i,j, n = text.size(), m = pattern.size(), t=0, p=0, h=1;

    for(i=0; i<m-1; i++) 
        h = (h*d)%q;

    for( i=0; i<m; i++){
        p = (d*p + pattern[i]) % q;
        t = (d*t + text[i]) % q;
    }

    for(i=0; i<=n-m; i++){
        if(t == p){
            for(j=0; j<m; j++){
                if(text[i+j]!=pattern[j]){
                    break;
                }
            }
            if(j==m) return i;
        }

        if(i < n-m){
            t = (d*(t - text[i]*h)+text[i+m]) % q;
            if(t<0) t = t+q;
        }
    }
    return -1;
}
int *calculateLPS(string pattern){
    int j = 0, i = 1,  m = pattern.size();
    
    int *LPS = (int *) malloc(sizeof(int)*m);
    LPS[0] = 0;

    while(i<m){
        if(pattern[i]==pattern[j]){
            j++;
            LPS[i] = j;
            i++;
        }else{
            if(j!=0){
                j = LPS[j-1];
            }else{
                LPS[i] = 0;
                i++;
            }
        }
    }
    return LPS;
}
void kmp(string text, string pattern){
    int *LPS = calculateLPS(pattern);
    int i=0, j=0, n = text.size(), m = pattern.size();

    while(i<n){
        if(pattern[j] == text[i]){
            i++;
            j++;
        }
        if(j == m){
            cout<<"Found pattern at "<<i-j<<endl;
            j = LPS[j-1];
        }
        else if(pattern[j]!=text[i] && i<n){
            if(j!=0){
                j = LPS[j-1];
            }else{
                i++;
            }
        }
    }
}

int main(){
    string text = "abdksndndnslkd";
    string pattern = "ndnd";
    cout<<"Pattern exists at index: "<<naiveMatching(text,pattern)<<endl;
    cout<<"Pattern exists at index: "<<rabinKarp(text,pattern)<<endl;
    kmp(text,pattern);
}

//mkdir -p .output && g++ -std=c++11 substring_match.cpp -o .output/substring_match.o && ./.output/substring_match.o