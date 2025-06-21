#include<bits/stdc++.h>
using namespace std;
class node{
public:
int data;
node*next;
node* prev;
node(int val){
    this->data=val;
    this->next=NULL;
    this->prev=NULL;
}
};
class Solution{
public: 
node* del(node* head , int key){
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            if(temp==head){
                head=head->next;
            }
            node* nextnode=temp->next;
            node* prevnode=temp->prev;
            if(nextnode!=NULL) nextnode->prev=prevnode; 
            if(prevnode!=NULL) prevnode->next=nextnode;
        }
        free(temp);
        temp=temp->next;
    }
    return head;
}
};