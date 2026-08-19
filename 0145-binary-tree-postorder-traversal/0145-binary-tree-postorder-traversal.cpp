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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root){
            return {};
        }
        vector<int> ans;
        stack<TreeNode*> s1,s2;

        s1.push(root);

        while(!s1.empty()){
            TreeNode *curr=s1.top();
            s1.pop();
            s2.push(curr);

            if(curr->left!=NULL){
                s1.push(curr->left);
            }
            if(curr->right !=NULL){
                s1.push(curr->right);
            }
        }
        while(!s2.empty()){
            ans.push_back(s2.top()->val);
            s2.pop();
        }
        return ans;
    }
};




// vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         postOrder(root,ans);
//         return ans;
//     }
//     void postOrder(TreeNode *root,vector<int> &ans){
//         if(root==NULL){
//             return;
//         }
//         postOrder(root->left,ans);
//         postOrder(root->right,ans);
//         ans.push_back(root->val);
        
//     }



// vector<int> ans;
//         stack<TreeNode*> s;
//         TreeNode* curr = root;
//         TreeNode *prev=NULL;

//         while (curr != NULL || !s.empty()) {
//             while (curr != NULL) {
//                 s.push(curr);
//                 curr=curr->left;
//             }
//             curr=s.top();
//             if(curr->right !=NULL && curr->right != prev){
//                 curr=curr->right;
//             }else{
//                 ans.push_back(curr->val);
//                 s.pop();
//                 prev=curr;
//                 curr=NULL;
//             }
//         }
//         return ans;