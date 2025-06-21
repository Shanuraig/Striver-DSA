#include<bits/stdc++.h>
using namespace std;
struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};
class  Solution{
    public: 
    int helper(ListNode* temp){
        if(temp==NULL) return 1;
        int carry=helper(temp->next);
        temp->val=temp->val+carry;
        if(temp->val<10){
            return 0;
        }
        temp->val=0;
        return 1;
    }
    ListNode* function(ListNode* head){
        int carry=helper(head);
        if(carry==1){
            ListNode* newnode=new ListNode(1);
            newnode->next=head;
            return newnode;
        }
        return head;
    }
};