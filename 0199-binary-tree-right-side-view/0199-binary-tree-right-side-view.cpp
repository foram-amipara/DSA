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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;

        map<int, int> m; 
        queue<pair<TreeNode*, int>> q;

        q.push(make_pair(root, 0));
        
        while(!q.empty()){
            pair<TreeNode*, int> curr = q.front();
            q.pop();
            
            TreeNode* node = curr.first;
            int level = curr.second;

            if(m.count(level) == 0){
                m[level] = node->val;
            }
            
            if (node->right != NULL) {
                q.push(make_pair(node->right, level + 1));
            }
            if (node->left != NULL) {
                q.push(make_pair(node->left, level + 1));
            }
        }
        
        for (auto it : m) {
            ans.push_back(it.second);
        }

        return ans;
    }
};