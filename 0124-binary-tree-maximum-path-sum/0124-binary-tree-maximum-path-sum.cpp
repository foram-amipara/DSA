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
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        getSum(root,ans);
        return ans;
    }
    int getSum(TreeNode* root,int &ans){
        if(root==NULL){
            return 0;
        }
        int leftSum=getSum(root->left,ans);
        int rightSum=getSum(root->right,ans);

        int orgLeft=max(0,leftSum);
        int orgRight=max(0,rightSum);

        int currSum=orgLeft+orgRight+root->val;
        ans=max(ans,currSum);
        return root->val+ max(orgLeft,orgRight);
    }
};