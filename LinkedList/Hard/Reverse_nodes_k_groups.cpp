#include<bits/stdtr1c++.h>
using namespace std;
class node{
public : 
int data;
node* next;
};
class solution{
public : 
node* reverse(node* head){
    node* temp=head;
    node* prev=NULL;
    while(temp!=NULL){
        node* fore=temp->next;
        temp->next=prev;
        prev=temp;
        temp=fore;
    }
    return prev;
}
node* findkthnode(node* head ,int k){
    k-=1;
    while(head!=NULL && k>0){
        k--;
        head=head->next;
    }
    return head;
}
node* reverseknode(node* head , int k){
    node* temp=head;
    node* prevnode=NULL;
    while(temp!=NULL){
        node* kthnode=findkthnode(temp,k);
        if(kthnode==NULL){
            if(prevnode) prevnode->next=temp;
            break;
        }
        node* nextnode=kthnode->next;
        kthnode->next=NULL;
        reverse(temp);
        if(temp==head){
            head=kthnode;
        }
        else{
            prevnode->next=kthnode;
        }
        prevnode=temp;
        temp=nextnode;
    }
    return head;
}
};