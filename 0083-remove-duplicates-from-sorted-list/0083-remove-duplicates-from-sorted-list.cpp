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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *curr=head;
        if (head == nullptr) return head;
        
        while(curr != nullptr && curr->next != nullptr){
            ListNode *nextOne=curr->next;
            if(curr->val==nextOne->val){
                curr->next=nextOne->next;
                nextOne->next==NULL;
            }else{
                curr=curr->next;
            }
            }
        return head;
    }
};