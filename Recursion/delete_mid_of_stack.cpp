#include <iostream>
#include <stack>
using namespace std;
void mDelete(stack<int> &st, int k){
    if(st.size()==k){
        st.pop();
        return;
    }

    int top = st.top();
    st.pop();
    mDelete(st, k);
    st.push(top);
}

int main(){

    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    int k = st.size()/2 + 1;
    mDelete(st,k);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    return 0;
}