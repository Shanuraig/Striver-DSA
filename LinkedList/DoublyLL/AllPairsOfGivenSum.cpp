#include<bits/stdc++.h>
using namespace std;
class node{
public:
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
public: 
node* findtail(node* head){
    node* temp=head;
    while(temp!=NULL) temp=temp->next;
    return temp;
}
vector<pair<int,int>> findpairs(node* head ,int sum){
    vector<pair<int,int>> res;
    node* left=head;
    node* right=findtail(head);
    while(left->data < right->data){
        if(left->data+right->data == sum){
            res.push_back({left->data , right->data});
            left=left->next;
            right=right->next;
        }
        else if(left->data+right->data<sum){
            left=left->next;
        }
        else{
            right=right->next;
        }
    }
    return res;
}
};