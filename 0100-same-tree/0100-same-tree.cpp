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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return isIdentical(p, q);
    }
    bool isIdentical(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL){
            return true;
        }else if(p == NULL || q == NULL){
            return false;
        }
        
        if(p->val != q->val){
            return false;
        }

        bool isLeft = isIdentical(p->left, q->left);
        bool isRight = isIdentical(p->right, q->right);
        if(isLeft && isRight){
            return true;
        }else if(isLeft || isRight){
            return false;
        }
        return false;
    }
};