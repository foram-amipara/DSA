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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.empty()) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        int i = 1; 
        while(i < preorder.size() && preorder[i] < root->val){
            i++;
        }

        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin()+i);
        vector<int> rightPreorder(preorder.begin() + i, preorder.end());

        root->left = bstFromPreorder(leftPreorder);
        root->right = bstFromPreorder(rightPreorder);
        
        return root;
    }
};