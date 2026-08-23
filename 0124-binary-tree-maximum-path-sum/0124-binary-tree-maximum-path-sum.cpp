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
        int ans = INT_MIN;
        calculateSum(root, ans);
        return ans;
    }
    int calculateSum(TreeNode* root, int &ans) {
        if (root == NULL) {
            return 0;
        }
        int left = calculateSum(root->left, ans);
        int right = calculateSum(root->right, ans);
        int leftMax = max(0, left);
        int rightMax = max(0, right);

        int currSum = root->val + leftMax + rightMax;
        ans = max(ans, currSum);
        return root->val + max(leftMax, rightMax);
    }
};