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
    vector<int> v;

    void inorder(TreeNode* root) {
        if (root == NULL)
            return;

        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }

    TreeNode* build(int low, int high) {
        if (low > high)
            return NULL;

        int mid = (low + high) / 2;

        TreeNode* root = new TreeNode(v[mid]);

        root->left = build(low, mid - 1);
        root->right = build(mid + 1, high);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        v.clear();
        inorder(root);

        return build(0, v.size() - 1);
    }
};