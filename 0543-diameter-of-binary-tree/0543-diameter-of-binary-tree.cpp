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
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
    }
    int diameter=0;
    int height(TreeNode *root){
        if(root==NULL){
            return 0;
        }
        int leftHt=height(root->left);
        int rightHt=height(root->right);
        diameter=max(diameter,leftHt+rightHt);

        return max(leftHt,rightHt)+1;
    }
};







// int diameterOfBinaryTree(TreeNode* root) {
//         return calculateDia(root);
//     }
//     int getHeight(TreeNode* root){
//         if(root==NULL){
//             return 0;
//         }
//         int leftHt=getHeight(root->left);
//         int rightHt=getHeight(root->right);
//         int height=max(leftHt,rightHt)+1;

//         return height;

//     }
//     int calculateDia(TreeNode *root){
//         if(root==NULL){
//             return 0;
//         }
//         int currDia=getHeight(root->left)+getHeight(root->right);
//         int leftDia=calculateDia(root->left);
//         int rightDia=calculateDia(root->right);
//         int ans =max({currDia,rightDia,leftDia});
//         return ans;
//     }