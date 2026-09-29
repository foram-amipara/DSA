/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long> maxHeap;
    
        if(root==NULL){
            return NULL;
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        long long currSum=0;
        while(!q.empty()){
            TreeNode* curr=q.front();
            if(curr!=NULL){
                currSum+=curr->val;
            }
            q.pop();
            if(curr==NULL){
                maxHeap.push(currSum);
                currSum=0;
                if(q.empty()){
                    break;
                }
                q.push(NULL);
            }else{
                if(curr->left!=NULL){
                    q.push(curr->left);
                }
                if(curr->right!=NULL){
                    q.push(curr->right);
                }
            }
        }
        long long count = 0;
        if(k>maxHeap.size()){
            return -1;
        }
        while (!maxHeap.empty() && count < k-1 ) {
            count++;
            maxHeap.pop();
        }
        return maxHeap.top();
    }
};