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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector <int>> ans;
        getAns(root,ans);
        return ans;

    }
    void getAns(TreeNode *root, vector<vector<int>> &ans){
        if(root==NULL) return;
        bool leftToRight=true;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> currVec;

        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            
            
            if(curr==NULL){
                if(!leftToRight){
                    reverse(currVec.begin(), currVec.end());
                }
                ans.push_back(currVec);
                currVec.clear();

                if(q.empty()){
                    break;
                }
                q.push(NULL);
                leftToRight=!leftToRight;
            }else{
                
                currVec.push_back(curr->val);
                if(curr->left!=NULL){
                q.push(curr->left);
                }
                if(curr->right!=NULL){
                    q.push(curr->right);
                }
            }
           
        }

    }

};










// vector<vector<int>> result;
//         if (root == nullptr) return result;

//         queue<TreeNode*> q;
//         q.push(root);
//         bool ltr = true;

//         while (!q.empty()) {
//             int size = q.size();
//             vector<int> level(size);

//             for (int i = 0; i < size; ++i) {
//                 TreeNode* curr = q.front();
//                 q.pop();
//                 int index = ltr ? i : (size - 1 - i);
//                 level[index] = curr->val;

//                 if (curr->left) q.push(curr->left);
//                 if (curr->right) q.push(curr->right);
//             }

//             result.push_back(level);
//             ltr = !ltr;
//         }

//         return result;

