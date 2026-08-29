/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int calclen(ListNode* newhead){
        ListNode* temp=newhead;
        int cnt=0;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1=calclen(headA);
        int l2=calclen(headB);
        if(l2>l1) return getIntersectionNode(headB,headA);
        int comlen=l1-l2;
        ListNode *temp1=headA;
        while(comlen>0){
            temp1=temp1->next;
            comlen--;
        }
        ListNode *temp2=headB;
        while(temp2!=NULL){
            if(temp1==temp2){
                return temp1;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return NULL;
    }
};