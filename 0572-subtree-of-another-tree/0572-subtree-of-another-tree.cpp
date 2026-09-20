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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL && subRoot == NULL ){
            return true;
        }else if(root==NULL || subRoot==NULL){
            return false;
        }

        if(root->val == subRoot->val){
            if(isIdentical(root,subRoot)){
                return true;
            }
        }

        bool isLeft=isSubtree(root->left,subRoot);
        if(!isLeft){
            return isSubtree(root->right,subRoot);
        }
        return true;

    }
    bool isIdentical(TreeNode* n1,TreeNode* n2){
         
        if(n1==NULL && n2==NULL){
            return true;
        }else if (n1==NULL || n2==NULL){
            return false;
        }
        if(n1->val != n2->val ){
            return false;
        }

        bool leftIdentical =isIdentical(n1->left,n2->left);
        bool rightIdentical =isIdentical(n1->right,n2->right);

        if(leftIdentical && rightIdentical){
            return true;
        }
        return false;
    }
};