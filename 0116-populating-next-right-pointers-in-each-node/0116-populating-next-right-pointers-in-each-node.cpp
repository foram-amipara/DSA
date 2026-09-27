
class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL){
            return NULL;
        }
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
       
        while(!q.empty()){
            Node* curr=q.front();
            q.pop();
            if(curr==NULL){
                if(q.empty()){
                    break;
                }
                q.push(NULL);
            }else{
                curr->next=q.front();
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
            }

        }
        return root;
    }
};