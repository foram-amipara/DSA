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
    int calSize(ListNode *head){
        ListNode *temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *val1=head;
        ListNode *val2=head;
        int count1=1;
        int count2=1;
        int n=calSize(head);
        while(count1<k){
            val1=val1->next;
            count1++;
        }
        while(count2<n-k+1){
            val2=val2->next;
            count2++;
        }
        swap(val1->val,val2->val);
        return head;
    }
};