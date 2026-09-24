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
    void recoverTree(TreeNode* root) {
        TreeNode* node1 = NULL;
        TreeNode* node2 = NULL;
        TreeNode* prev = NULL;
        validate(root, prev, node1, node2);
        if (node1 && node2) {
            swap(node1->val, node2->val);
        }
    }
    void validate(TreeNode* root, TreeNode*& prev, TreeNode*& node1, TreeNode*& node2) {
        if (root == NULL) {
            return;
        }
        validate(root->left, prev, node1, node2);
        if (prev != NULL && root->val < prev->val) {
            if (node1 == NULL) {
                node1 = prev;
                node2 = root;
            } else {
                node2 = root;
            }
        }
        prev = root;
        validate(root->right, prev, node1, node2);
    }
     
};