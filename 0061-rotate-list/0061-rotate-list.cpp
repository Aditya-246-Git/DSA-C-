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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        int len=lengthofLL(head);
        k=k%len;
        if(k==0) return head;
        int travlen=len-k-1;
        ListNode* tail=head;
        ListNode* breaknode=head;
        ListNode* newhead=head;
        while(tail->next){
          if(travlen==0) {
            breaknode=tail;
            newhead=tail->next;
         }
          travlen--;
          tail=tail->next; 
        }
        breaknode->next=NULL;
        tail->next=head;
        return newhead;
    }
};