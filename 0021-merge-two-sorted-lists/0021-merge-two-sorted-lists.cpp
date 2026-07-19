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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;

        ListNode *temp1 = list1;
        ListNode *temp2 = list2;
        ListNode *prev = NULL;
        ListNode *head = NULL;
        
        while (temp1 != NULL && temp2 != NULL) {
            ListNode *next1 = temp1->next;
            ListNode *next2 = temp2->next;
            
            if (temp1->val == temp2->val) {
                if (prev != NULL) {
                    prev->next = temp1;
                    temp1->next = temp2;
                    prev = temp2;
                } else {
                    head = temp1;
                    temp1->next = temp2;
                    prev = temp2;
                }
                temp1 = next1;
                temp2 = next2;
            }
            else if (temp1->val < temp2->val) {
                if (prev != NULL) {
                    prev->next = temp1;
                    prev = temp1;
                } else {
                    head = temp1;
                    prev = temp1;
                }
                temp1 = next1;
            }
            else if (temp1->val > temp2->val) {
                if (prev != NULL) {
                    prev->next = temp2;
                    prev = temp2;
                } else {
                    head = temp2;
                    prev = temp2;
                }
                temp2 = next2;
            }
        }

        if (temp1 != NULL) {
            prev->next = temp1;
        } else {
            prev->next = temp2;
        }

        return head;
    }
};