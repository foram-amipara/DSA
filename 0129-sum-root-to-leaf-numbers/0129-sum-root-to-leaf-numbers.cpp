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
//all possible paths to leafnodes
    int sumNumbers(TreeNode* root) {
        stack<int> s;
        int sum = 0;
        int num = 0;
        
        traverse(root, s, sum, num);
        
        return sum;

    }
    void traverse(TreeNode* root , stack<int> &s,int &sum,int &num){
        if(root==NULL){
            return;
        }
        s.push(root->val);
        if (root->left == NULL && root->right == NULL) {
            sum += getNum(s);
        }else{
            traverse(root->left,s,sum,num);
            traverse(root->right,s,sum,num);
        }

        s.pop();

    }
    int getNum(stack<int> s){ 
        long long currentNum = 0;
        long long multiplier = 1;
        
        while (!s.empty()) {
            currentNum += s.top() * multiplier;
            s.pop();
            multiplier *= 10;
        }
        
        return currentNum;
    }
};