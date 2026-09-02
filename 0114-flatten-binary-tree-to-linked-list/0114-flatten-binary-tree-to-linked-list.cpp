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
    void flatten(TreeNode* root) {
        vector<int> ans;

        preOrder(root, ans);

        getAns(root, ans);
    }

    void preOrder(TreeNode* root, vector<int>& ans) {
        if (root == NULL) {
            return;
        }

        ans.push_back(root->val);

        preOrder(root->left, ans);
        preOrder(root->right, ans);
    }

    void getAns(TreeNode* root, vector<int>& ans) {
        if (root == NULL) {
            return;
        }

        TreeNode* curr = root;

        for (int i = 1; i < ans.size(); i++) {
            curr->left = NULL;

            curr->right = new TreeNode(ans[i]);

            curr = curr->right;
        }

        curr->left = NULL;
    }
};
