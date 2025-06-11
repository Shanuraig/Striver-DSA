#include<bits/stdc++.h>
using namespace std;
struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
 public:
  bool isPalindrome(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast->next->next != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }
    slow = reverseList(slow->next);

    while (slow != nullptr) {
      if (slow->val != head->val)
        return false;
      slow = slow->next;
      head = head->next;
    }

    return true;
  }

 private:
  ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    while (head != nullptr) {
      ListNode* next = head->next;
      head->next = prev;
      prev = head;
      head = next;
    }
    return prev;
  }
};