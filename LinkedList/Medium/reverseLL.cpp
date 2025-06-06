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
node* reversell(node* head){
    node*prev=nullptr;
    node*curr=head;
    while(curr!=nullptr){
        node*foreward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=foreward;
    }
    return prev;//head
}