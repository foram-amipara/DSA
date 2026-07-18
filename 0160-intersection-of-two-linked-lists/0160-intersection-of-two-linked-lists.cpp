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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *currA=headA;
        ListNode *currB=headB;

        while(currA!=NULL || currB!=NULL){
            if(currA==NULL){
                currA=headB;
            }
            if(currB==NULL){
                currB=headA;
            }
            if(currA==currB){
                return currA;
            }
            currA=currA->next;
            currB=currB->next;
        }
        return NULL;

    }
};