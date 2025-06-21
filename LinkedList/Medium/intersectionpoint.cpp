#include<bits/stdc++.h>
using namespace std;
struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};
class solution {
public :
//This is a 2 pass solution 
ListNode* intersection(ListNode* head1,ListNode* head2){
    ListNode* temp=head1;
    map<ListNode*,int> mpp;
    while(temp!=NULL){
        mpp[temp]=1;
        temp=temp->next;
    }  
    temp=head2;
    while(temp!=NULL){
        if(mpp.find(temp)!=mpp.end()){
                return temp;
        }
        temp=temp->next;
    }  
    return NULL;
}
//We are going to degin a 1 pass solution 
ListNode* onepassintersection(ListNode* head1 , ListNode* head2){
        
}
};
