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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode* val1=l1;
       ListNode* val2=l2;
       int carry=0;
       ListNode* newhead=new ListNode(-1);
       ListNode* temp=newhead;
       while(val1!=NULL && val2!=NULL){
         int sum=val1->val + val2->val + carry;
         carry=sum/10;
         int finalval=sum%10;
         temp->next = new ListNode(finalval);
         temp=temp->next;
         val1=val1->next;
         val2=val2->next;
       } 
       while(val1!=NULL){
          int sum=val1->val + carry;
        carry=sum/10;
         int finalval=sum%10;
         temp->next = new ListNode(finalval);
         temp=temp->next;
         val1=val1->next;
       }
       while(val2!=NULL){
        int sum= val2->val + carry;
         carry=sum/10;
         int finalval=sum%10;
         temp->next = new ListNode(finalval);
         temp=temp->next;
         val2=val2->next;
       }
       if(carry!=0){
         temp->next = new ListNode(carry);
         temp=temp->next;
       }
       return newhead->next;
    }
};