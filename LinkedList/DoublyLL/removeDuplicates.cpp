#include<bits/stdc++.h>
using namespace std;
class node{
public :
int data;
node* next;
node* prev;
node(int data){
    this->data=data;
    this->next=NULL;
    this->prev=NULL;
}
};
class Solution{
public : 
node* removeduplicate(node* head){
    node* temp=head;
    while(temp!=NULL && temp->next!=NULL){
        node* nextnode=temp->next;
        while(nextnode!=NULL && temp->data==nextnode->data){
            nextnode=nextnode->next;
        }
        temp->next=nextnode;
        if(nextnode!=NULL) nextnode->prev=temp;
        temp=temp->next;
    }
    return head;
}
};