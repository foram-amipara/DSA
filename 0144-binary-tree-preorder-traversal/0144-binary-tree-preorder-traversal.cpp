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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* curr = root;

        while (curr != NULL || !s.empty()) {
            while (curr != NULL) {
                ans.push_back(curr->val);
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            curr = curr->right;         
        }
        return ans;
    }
};



// vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         preOrder(root,ans);
//         return ans;
    
//     }
//     void preOrder(TreeNode* root,vector<int> &ans){
//         if(root==NULL){
//             return;
//         }
//         ans.push_back(root->val);
//         preOrder(root->left,ans);
//         preOrder(root->right,ans);
//     }
// }