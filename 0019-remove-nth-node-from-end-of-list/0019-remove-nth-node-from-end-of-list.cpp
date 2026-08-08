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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp=new ListNode(0,head);
        ListNode *fast=temp;
        ListNode *slow=temp;
        
        for(int i=0;i<=n;i++){
            fast=fast->next;
        }

        while(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        ListNode *deleteNode =slow->next;
        slow->next=slow->next->next;
        delete deleteNode;

        ListNode *newHead=temp->next;
        delete temp;
        return newHead;
    }
};



// int count=0;
//         ListNode *nextOne=NULL;
//         ListNode *temp1=head;
//         ListNode *temp2=head;
//         if(head->next==NULL){
//             return NULL;
//         }

//         while(temp1!=NULL){
//             count++;
//             temp1=temp1->next;
//         }
        
//         int node=count-n;
//         int nodeCount=1;
//         if (node == 0) {
//             ListNode* toDelete = head;
//             head = head->next; 
//             delete toDelete;  
//             return head; 
//         }
        
//         while(nodeCount != node){
//             temp2 = temp2->next;
//             nodeCount++;
//         }
//         nextOne=temp2->next;
//         temp2->next=nextOne->next;
//         nextOne->next=NULL;
//         delete nextOne;

//         return head;