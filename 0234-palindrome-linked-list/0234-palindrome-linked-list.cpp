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
        ListNode *curr=head;
        ListNode *prev=NULL;
        while(curr!=NULL){
            ListNode *nextOne =curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextOne;
        }
        head=prev;
        return head;
    }
    ListNode* splitMid(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *right = head;
        ListNode *mid=splitMid(head);
        ListNode *left = reverseList(mid);
        while (left != NULL) {
            if (right->val != left->val) {
            return false;
            }
            right = right->next;
            left = left->next;
        }
        return true;
        return true;
    }
};