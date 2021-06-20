#include<iostream>
#include<unordered_map>

using namespace std;

unordered_map<string,bool> mp;

bool scrambledStringMCM(string a, string b){
    if(a.compare(b)==0) return true;
    if(a.length()<=1) return false;
    string key = a+"_"+b;
    if(mp.find(key)!=mp.end()) return mp[key];

    int n = a.length();
    bool flag = false;
    for(int i=1; i<n; i++){
        bool c1 = scrambledStringMCM(a.substr(0,i),b.substr(n-i,i)) && 
                   scrambledStringMCM(a.substr(i,n-i),b.substr(0,n-i));

        bool c2 = scrambledStringMCM(a.substr(0,i),b.substr(0,i)) &&
                  scrambledStringMCM(a.substr(i,n-i),b.substr(i,n-i));
        if(c1 || c2) {
            flag = true;
            break;
        }
    }
    return mp[key] = flag;
}
bool scrambledString(string a, string b){
    if(a.size()!=b.size()) return false;
    if(a.empty() && b.empty()) return false;
    return scrambledStringMCM(a,b);
}
int main(){
    string a = "abbbcbaaccacaacc";
    string b = "acaaaccabcabcbcb";

    cout<<"Scrambled string : "<<scrambledString(a,b)<<endl;
}