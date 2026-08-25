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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<pair<int, int>, vector<int>> mp;
        
        dfs(ans, 0, 0, root, mp);

        int lastCol = INT_MIN;
        for (auto p : mp) {
            int col = p.first.first;
            vector<int> values = p.second;

            sort(values.begin(), values.end());
            
            if (ans.empty() || col != lastCol) {
                ans.push_back({});
                lastCol = col;
            }
            
            for (int val : values) {
                ans.back().push_back(val);
            }
        }

        return ans;
    }
    void dfs(vector<vector<int>>& ans, int idx, int ht, TreeNode* root, map<pair<int, int>, vector<int>>& mp) {
        if (root == nullptr) return;

        mp[{idx, ht}].push_back(root->val);

        dfs(ans, idx - 1, ht + 1, root->left, mp);
        dfs(ans, idx + 1, ht + 1, root->right, mp);
    }

    
};