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
    bool isBalanced(TreeNode* root) {
        return balancedNode(root);
    }
    bool balancedNode(TreeNode *root){
        if(root==NULL){
            return true;
        }
        
        int leftDepth=calculateDepth(root->left);
        int rightDepth=calculateDepth(root->right);
        if(leftDepth-rightDepth==1 || leftDepth-rightDepth== -1 || leftDepth-rightDepth==0 ){
            bool left=balancedNode(root->left);
            bool right=balancedNode(root->right);
            if(left && right){
                return true;
            }else{return false;}
            
        }
        return false;
        
    }
    int calculateDepth(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int leftHt=calculateDepth(root->left);
        int rightHt=calculateDepth(root->right);
        int height=max(leftHt,rightHt)+1;

        return height;

    }
};