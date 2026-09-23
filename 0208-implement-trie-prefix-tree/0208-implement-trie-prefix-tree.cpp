class Trie {
public:
    struct Node{
        unordered_map<char,Node*> info;
        bool endOfWord;
        Node(){
            endOfWord=false;
        }
    };
    Node* root;
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* temp=root;
        for(int i=0;i<word.length();i++){
            if(temp->info.count(word[i])==0){
                temp->info[word[i]]=new Node();
            }
            temp=temp->info[word[i]];
        }
        temp->endOfWord=true;
    }
    
    bool search(string word) {
        Node* temp = root;
        for(int i=0;i<word.length();i++){
            if(temp->info.count(word[i])){  
                temp=temp->info[word[i]];     
            }else{return false;}
        }
        return temp->endOfWord;
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;
        for(int i=0;i<prefix.length();i++){
            if(temp->info.count(prefix[i])){  
                temp=temp->info[prefix[i]];     
            }else{return false;}
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */