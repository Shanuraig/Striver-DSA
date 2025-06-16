#include<bits/stdc++.h>
using namespace std;
struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* findmiddle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode* dummynode=new ListNode(-1);
        ListNode* temp=dummynode;
        while(l1!=NULL && l2!=NULL) {
            if(l1->val<l2->val){
                temp->next=l1;
                temp=l1;
                l1=l1->next;
            }
            else{
                temp->next=l2;
                temp=l2;
                l2=l2->next;
            }
        }
        if(l1) temp->next=l1;
        else temp->next=l2;
        return dummynode->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* middle=findmiddle(head);
        ListNode* right=middle->next;
        middle->next=NULL;
        ListNode* left=head;
        left = sortList(left);
        right = sortList(right);
        return merge(left,right);
    }
};