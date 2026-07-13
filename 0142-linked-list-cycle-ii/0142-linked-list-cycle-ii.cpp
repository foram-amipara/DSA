class Solution {
public:
    ListNode* isCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;

        ListNode *fast = head;
        ListNode *slow = head;

        while (fast!=NULL && fast->next!=NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                return fast;
            }
        }
        return nullptr;
    }

    ListNode *detectCycle(ListNode *head) {
        ListNode *intersect = isCycle(head);
        if (!intersect) {
            return nullptr;
        }

        ListNode *slow = head;
        ListNode *fast = intersect;

        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};