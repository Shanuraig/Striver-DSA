#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int val;
    node *next;
    node *prev;
    node(int val)
    {
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};
//conversion of vector to doubly linked list 
node* converarrtoDoublyll(vector<int> &arr){
    node*head=new node(arr[0]);
    node*prev=head;
    for(int i=1;i<arr.size();i++){
        node* temp=new node(arr[i]);
        temp->prev=prev;
        prev->next=temp;
        prev=temp;
    }
    return head;
}
void print(node* head){
    node*temp=head;
    while(temp!=nullptr){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}
//deleting head of the doubly linked list
node* delhead(node* head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    node* todelete=head;
    head=head->next;
    head->prev=nullptr;
    todelete->next=nullptr;
    delete todelete;
    return head;
}
//deleting the tail of the linked list
node* deltail(node* head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    node* tail=head;
    while(tail->next!=nullptr){
        tail=tail->next;
    }
    node* newtail=tail->prev;
    tail->prev=nullptr;
    newtail->next=nullptr;
    delete tail;
    return head;
}
//deleting kth element fromt he doubly linked list
node* deleteKelement(node* head,int k){
    if(head==NULL || head->next==NULL) return NULL;
    int cnt=0;
    node*temp=head;
    while(temp->next!=NULL){
        cnt++;
        if(cnt==k) break;
        temp=temp->next;
    }
    node* curr=temp->prev;
    node* front=temp->next;
    curr->next=front;
    front->prev=curr;
    if(curr==NULL && front==NULL){
        delete temp;
        return NULL;
    }
    else if (curr==NULL){
        return delhead(head);
    }
    else if(front==NULL){
       return deltail(head);
    }
    curr->next=front;
    front->prev=curr;
    temp->next=nullptr;
    temp->prev=nullptr;
    delete temp;
    return head;
}
//delete a given node form a doubly linked list 
void delnode(node* todelete){
    node*back=todelete->prev;
    node*front=todelete->next;
    if(front==NULL){
        back->next=NULL;
        free(todelete);
    }
    back->next=front;
    front->prev=back;
    todelete->prev=todelete->next=NULL;
    free(todelete);
}
void insertathead(node*&head,int d){
    node*temp=new node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
}
void insertattail(node*&tail,int d){
    node*temp=new node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}
int main(){
    vector<int> arr={1,2,3,4,5,6};
    node*head=converarrtoDoublyll(arr);
    print(head);
    head=delhead(head);
    cout<<endl;
    print(head);
    head=deltail(head);
    cout<<endl;
    print(head);
    cout<<endl;
    head=deleteKelement(head,3);
    print(head);
    cout<<endl;
    delnode(head->next);
    print(head);
    cout<<endl;
    insertathead(head,1);
    print(head);
}


