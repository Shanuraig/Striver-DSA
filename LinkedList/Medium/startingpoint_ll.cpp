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
node* startingpoint(node* head){
    node*slow=head;
    node*fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            slow=head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
        return NULL;
    }
}