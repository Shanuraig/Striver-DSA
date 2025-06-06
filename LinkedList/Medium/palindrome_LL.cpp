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
class solution{
public: 
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
//optimal solution two pointer approach
bool palindrome(node* head){
    node* slow=head;
    node* fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    if(fast!=nullptr){
        slow=slow->next;
        slow=reverselist(slow);
    }
    while(slow!=nullptr){
        if(slow->data != head->data ) return false;
        slow=slow->next;
        head=head->next;
    }
    return true;
}
private:
node* reverselist(node* head){
    node* prev=nullptr;
    node*curr=head;
    while(curr!=nullptr){
        node*next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
};


