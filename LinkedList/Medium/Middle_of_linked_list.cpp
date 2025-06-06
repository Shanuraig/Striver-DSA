#include<bits/stdc++.h>
using namespace std;
class node{
    public: 
    int data;
    node*next;
    node(int val){
        this->data=val;
        this->next=nullptr;
    }
};
node* convert(vector<int> &arr){
    node*head=new node(arr[0]);
    node*mover=head;
    for(int i=1;i<arr.size();i++){
        node* temp=new node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
node* middleNode(node* head) {
        node* slow=head;
        node* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
       return slow;
    }
void print(node*head){
    node*temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
    vector<int> arr={1,2,3,4,5};
    node*head=convert(arr);
    print(head);
    cout<<endl;
}