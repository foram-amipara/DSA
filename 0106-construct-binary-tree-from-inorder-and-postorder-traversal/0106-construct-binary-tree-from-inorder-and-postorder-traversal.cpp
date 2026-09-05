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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.empty() || inorder.empty()) {
            return nullptr;
        }
        int n=postorder.size();
        TreeNode* root = new TreeNode(postorder[n-1]);

        auto it=find(inorder.begin(),inorder.end(),postorder[n-1]);
        int rootIndex = it - inorder.begin();

        vector<int> leftPostorder(postorder.begin(), postorder.begin() + rootIndex);
        vector<int> leftInorder(inorder.begin(), inorder.begin() + rootIndex);
        
        vector<int> rightPostorder(postorder.begin() + rootIndex, postorder.end()-1);
        vector<int> rightInorder(inorder.begin() + rootIndex + 1, inorder.end());
        
        root->left = buildTree(leftInorder,leftPostorder);
        root->right = buildTree(rightInorder,rightPostorder);

        return root;
    }
};