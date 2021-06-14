#include <iostream>
#include <math.h>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}

};
void display(ListNode* l){
    ListNode* temp=l;
    while(temp!=nullptr){
        cout<<" "<<temp->val;
        temp = temp->next;
    }
    return;
}
void reversePrint(ListNode* l){
    if(l->next!=nullptr){
        reversePrint(l->next);
    }
    cout<<" "<<l->val;
    return;
}

 int recursiveSum(ListNode* l, int position, int sum){
       if(l->next!=nullptr){
        sum+= recursiveSum(l->next,position++,sum);
       }
       cout<<"sum = "<<sum<<" pos = "<<position<<" val = "<<l->val<<"\n";
       sum+=pow(10,position)*(l->val);
       return sum; 
}
ListNode* result;
    ListNode* reverse(ListNode* node) 
    { 
        if (node == NULL) 
            return NULL; 
        if (node->next == NULL) { 
            result = node; 
            return node; 
        } 
        ListNode* node1 = reverse(node->next); 
        node1->next = node; 
        node->next = NULL; 
        return node; 
    } 

int main(){

    ListNode* l1 = new ListNode(2);
    ListNode* l2 = new ListNode(3,l1);
    ListNode* l3 = new ListNode(4,l2);

    display(l3);
    cout<<"\n";
    // int num = recursiveSum(l3,0,0);
    // reversePrint(l3);
    // cout<<num;
    result = l3;
    result = reverse(result);
    display(result);
    // reversePrint(l3);

    return 0;
}