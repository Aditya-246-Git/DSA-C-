/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int lengthofLL(ListNode* head){
        ListNode* temp=head;
        int cnt=0;
        while(temp){
          cnt++;
          temp=temp->next;
        }
        return cnt;
    }
    pair<ListNode*, ListNode*> reverseList(ListNode* head) {
       if(head == NULL || head->next == NULL)
         return {head, head};
        ListNode* prev = nullptr;
        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* tail = head;   // original head becomes tail

       while(second != NULL) {
           first->next = prev;
           prev = first;
           first = second;
           second = second->next;
        }
        first->next = prev;
        return {first, tail};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
      if(head == NULL || head->next == NULL || k == 1)  return head;
      int len = lengthofLL(head);
      ListNode* groupHead = head;
      ListNode* newHead = NULL;
      ListNode* prevTail = NULL;
      while(len >= k) {
        ListNode* kth = groupHead;
        for(int i = 1; i < k; i++) {
            kth = kth->next;
        }
        ListNode* nextHead = kth->next;
        kth->next = NULL;
        auto result = reverseList(groupHead);
        ListNode* revHead = result.first;
        ListNode* revTail = result.second;
        if(newHead == NULL) {
            newHead = revHead;
        }
        else {
            prevTail->next = revHead;
        }
        prevTail = revTail;
        groupHead = nextHead;
        len -= k;
     }
      prevTail->next = groupHead;
      return newHead;
    }
};