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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* prev = nullptr;
        ListNode* first = head;
        ListNode* second = head->next;
        while(second!=NULL){
            first->next=prev;
            prev=first;
            first=second;
            second=second->next;
        }
        first->next=prev;
        return first;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        if(head==NULL || head->next==NULL) return true;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newhead=reverseList(slow->next);
        ListNode* temp=head;
        while(newhead!=NULL){
            if(newhead->val!=temp->val) return false;
            newhead=newhead->next;
            temp=temp->next;
        }
        return true;
    }
};