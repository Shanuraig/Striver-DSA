#include<bits/stdc++.h>
using namespace std;
struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};
class Solution{
public : 
//it is a 2 pass solution 
ListNode* sort012(ListNode* head){
    if(head==NULL || head->next==NULL) return head;
    ListNode* temp=head;
    int c0=0,c1=0,c2=0;
    while(temp!=NULL){
        if(temp->val==0){
            c0++;
        }
        else if (temp->val==1){
            c1++;
        }
        else{
            c2++;
        }
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        if(c0>0){
            temp->val=0;
            c0--;
        }
        else if(c1>0){
            temp->val=1;
            c1--;
        }
        else{
            temp->val=2;
            c2--;
        }
    temp=temp->next;
    }
    return temp;
}
// doing it in one pass
ListNode* sort012op(ListNode* head){
    if(head==NULL || head->next==NULL) return head;
    ListNode* temp=head;
    ListNode* zerohead=new ListNode(-1);
    ListNode* onehead=new ListNode(-1);
    ListNode* twohead=new ListNode(-1);
    ListNode* zero=zerohead;
    ListNode* one=onehead;
    ListNode* two=twohead;
    while(temp!=NULL){
        if(temp->val==0){
            zero->next=temp;
            zero=temp;
        }
        else if(temp->val==1){
            one->next=temp;
            one=temp;
        }
        else{
            two->next=temp;
            two=temp;
        }
        temp=temp->next;
    }
    zero->next=(onehead->next)?onehead->next:twohead->next;
    one->next=(twohead->next)?twohead->next:NULL;
    two->next=NULL;
    ListNode* newhead=zerohead->next;
    delete(zerohead);
    delete(onehead);
    delete(twohead);
    return newhead;
}
};