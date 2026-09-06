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
class Info{
    public:
    int min;
    int max;
    bool isBST;
    int sum;
    Info(bool isBST,int min,int max,int sum){
        this->isBST = isBST;
        this->min=min;
        this->max=max;
        this->sum=sum;
    }
};
class Solution {
public:
    int maxSum=0;
    int maxSumBST(TreeNode* root) {
        maxSum=0;
        bstSum(root);
        return maxSum;
    }
    Info* bstSum(TreeNode* root){
        if(root==NULL){
            return new Info(true,INT_MAX,INT_MIN,0);
        }

        Info* leftInfo=bstSum(root->left);
        Info* rightInfo=bstSum(root->right);

        int currMin=min(root->val,min(leftInfo->min,rightInfo->min));
        int currMax=max(root->val,max(leftInfo->max,rightInfo->max));

        int currSum=leftInfo->sum+rightInfo->sum+root->val;
    
        if(leftInfo->isBST && rightInfo->isBST && root->val>leftInfo->max && root->val<rightInfo->min){
            maxSum=max(maxSum,currSum);
            return new Info(true,currMin,currMax,currSum);
        }
        return new Info(false,currMin,currMax,currSum);

    }
    
};