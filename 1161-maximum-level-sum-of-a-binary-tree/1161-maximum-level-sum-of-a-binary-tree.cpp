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
    int maxSum=INT_MIN;
    pair<int,int> info;//maxsum,level

    int maxLevelSum(TreeNode* root) {
        levelOrder(root);
        return info.second;
    }

    void levelOrder(TreeNode* root){
        
        if(root==NULL){
            return;
        }

        int currSum=0;
        int currLevel=1;
        queue<TreeNode*> q;

        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();

            if(curr==NULL){
                if(currSum >maxSum){
                    maxSum=currSum;
                    info.second=currLevel;
                }
                currSum=0;
                currLevel++;
                if(q.empty()){
                    break;
                }
                q.push(NULL);
                continue;
            }
            currSum+=curr->val;

            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
                q.push(curr->right);
            }
        }
        
    }
};