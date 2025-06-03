#include<bits/stdc++.h>
using namespace std;
class node {
    public : 
    int data;
    node* next;
    node(int data){
        this->data=data;
        next=nullptr;
    }
};
node* convertarr2ll(vector<int> &arr){
    node*head=new node(arr[0]);
    node*mover=head;
    for(int i=1;i<arr.size();i++){
        node* temp=new node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
int lengthofll(node* head){
    int count=0;
    node*temp=head;
    while(temp!=nullptr){
        count++;
        temp=temp->next;
    }
    return count;
}
bool search(node* head , int val){
    node* temp=head;
    while(temp!=nullptr){
        if(temp->data==val) return true;
        temp=temp->next;
    }
    return false;
}
int main(){
   vector<int> arr={1,2,3,4,5,6};
   node* head=convertarr2ll(arr);
   node*temp=head;
   while(temp!=nullptr){
    cout<<temp->data<<" ";
    temp=temp->next;
   }
   cout<<endl<<lengthofll(head);
}