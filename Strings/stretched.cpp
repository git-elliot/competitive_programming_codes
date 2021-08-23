#include <iostream>
#include <stack>
using namespace std;
bool stretched3(string x, string y){
    stack<char> st;
    string s;
    for(int i=0; i<x.size(); i++){
        if(st.empty()){
            s.push_back(x[i]);
        }else if(st.top()!=x[i]){
            st.pop();
            s.push_back(x[i]);
        }
        st.push(x[i]);
    }

    return s == y;
}
bool stretched2(string x, string y){
    if(x.size() < y.size()) return stretched2(y,x);
    if(x.size() == y.size()) return x == y;
    int freq[26] = {0};
    string s;
    for(int i=0; i<x.size(); i++){
        if(freq[x[i]-'a']==0){
            s.push_back(x[i]);
        }
        freq[x[i]-'a'] = 1;
    }
    return s == y;
}

bool stretched1(string x, string y){
    int i=0, j=0;
    while(j<y.size()){
        if(x[i]==y[j]){
            i++;
        }else if(x[i]==y[j+1]){
            j++;
        }else{
            break;
        }
    }
    return i == x.size();
}

int main() {
    cout<<stretched1("aaaabbbbccccc","abc")<<endl;
	cout<<stretched1("aaaabbbbdcccc","abc")<<endl;
	cout<<stretched1("abc","abc")<<endl;
    cout<<endl;
    cout<<stretched2("aaaabbbbccccc","abc")<<endl;
	cout<<stretched2("aaaabbbbdcccc","abc")<<endl;
	cout<<stretched2("abc","abc")<<endl;
    cout<<endl;
	cout<<stretched3("aaaabbbbccccc","abc")<<endl;
	cout<<stretched3("aaaabbbbdcccc","abc")<<endl;
	cout<<stretched3("abc","abc")<<endl;
	return 0;
}
//mkdir -p .output && g++ -std=c++11 stretched.cpp -o .output/stretched.o && ./.output/stretched.o