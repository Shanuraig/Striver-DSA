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
int counter(node*head){
    int count=0;
    node*temp=head;
    while(temp!=nullptr){
        count++;
        temp=temp->next;
    }
    return count;
}
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
node* middle(){
    
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
    int c=counter(head);
    cout<<c<<endl;
}