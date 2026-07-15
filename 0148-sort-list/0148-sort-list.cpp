class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode *rightHead = splitMid(head);
        ListNode *right = sortList(rightHead);
        ListNode *left = sortList(head);
        
        return merge(left, right);
    }

    ListNode* splitMid(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = NULL;

        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (prev != NULL) {
            prev->next = NULL;
        }

        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        ListNode *i = left;
        ListNode *j = right;

        while (i != NULL && j != NULL) {
            if (i->val <= j->val) {
                tail->next = i;
                i = i->next;
            } else {
                tail->next = j;
                j = j->next;
            }
            tail = tail->next;
        }

        if (i != NULL) {
            tail->next = i;
        } else {
            tail->next = j;
        }

        ListNode* result = dummy->next;
        delete dummy;

        return result;
    }
};