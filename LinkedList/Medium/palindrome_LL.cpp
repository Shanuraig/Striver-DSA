#include<bits/stdc++.h>
using namespace std;
 class node{
public :
int data;
node*next;
node(int val){
    this->data=val;
    this->next=nullptr;
}
};
//better solution
bool ispalindrome(node* head){
    stack<int> st;
    node*temp=head;
    while(temp!=NULL){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        if(temp->data!=st.top()) return false;
        st.pop();
        temp=temp->next;
    }
    return true;
}
//optimal solution 
