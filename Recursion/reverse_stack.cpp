#include <iostream>
#include <stack>
using namespace std;

void mInsert(stack<int> &st, int ele){
    if(st.empty()){
        st.push(ele);
        return;
    }

    int top = st.top();
    st.pop();
    mInsert(st, ele);
    st.push(top);
    return;
}
void mReverse(stack<int> &st){
    if(st.size()==1){
        return;
    }
    int top = st.top();
    st.pop();
    mReverse(st);
    mInsert(st, top);
    return;

}

void display(stack<int> st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    
}
int main(){

    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    display(st);
    mReverse(st);
    display(st);
    return 0;
}