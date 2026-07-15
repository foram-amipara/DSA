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
    
    void reorderList(ListNode* head) {

        ListNode *rightHead = splitMid(head);
        ListNode *rightHeadReverse = reverse(rightHead);

        ListNode *left=head;
        ListNode *right=rightHeadReverse;
        ListNode *tail=right;
        while(left!=NULL && right!=NULL){
            ListNode *nextR=right->next;
            ListNode *nextL=left->next;
            left->next=right;
            right->next=nextL;
            tail=right;
            left=nextL;
            right=nextR;
        }
        if(right!=NULL){
            tail->next=right;
        }
    }

    ListNode* reverse(ListNode *head){
        ListNode *curr=head;
        ListNode *prev=NULL;
        while(curr!=NULL){
            ListNode *nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        head=prev;
        return head;
    }
    ListNode *splitMid(ListNode *head){
        ListNode *fast=head;
        ListNode *slow=head;
        ListNode *prev=NULL; 
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
        }
        if(prev != NULL){
            prev->next = NULL;
        } 
        return slow;
    }
};
