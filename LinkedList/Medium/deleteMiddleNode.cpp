#include<bits/stdc++.h>
using namespace std;
struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    int count(ListNode* head){
        int count=0;
        ListNode*temp=head;
        while(temp!=NULL){
                count++;
                temp=temp->next;
        }
        return count;
    }  
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL) return NULL;
         ListNode*temp=head;
        int N=count(head);
        int n=N/2;
        while(temp!=NULL){
            n--;
            if(n==0){
                ListNode* middle=temp->next;
                temp->next=temp->next->next;
                delete middle;
                break;
            }
            temp=temp->next;
        }
        return head;
    }
};