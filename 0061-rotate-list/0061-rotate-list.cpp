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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;
        ListNode *temp1=head;
        int count1=1;
        while(temp1->next!=NULL){
            count1++;
            temp1=temp1->next;
        }
        ListNode *temp2=head;
        int count2=1;
        k = k % count1;
        if (k == 0) return head;
        while(count2<count1-k){
            count2++;
            temp2=temp2->next;
        }
        ListNode *ans=temp2->next;
        temp2->next=NULL;
        temp1->next=head;

        return ans;
    }
};