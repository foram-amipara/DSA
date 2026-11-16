class Solution {
    public:
    class Node{
        public:
        bool endOfWord;
        unordered_map<char,Node*> children;
        
        Node(){
            endOfWord=false;
        }
    };
    
    class Trie{
        public:
        Node* root;
       
        Trie(){
            root=new Node();
        }
        void insert(string key){
            Node* temp =root;
            for(int i=0;i<key.length();i++){
                if(temp->children.count(key[i])==0){
                    temp->children[key[i]]=new Node(); 
                }
                temp=temp->children[key[i]];       
            }
            temp->endOfWord=true;
        }
        bool search(string key){
            Node* temp=root;
            for(int i=0;i<key.length();i++){
                if(temp->children.count(key[i])){
                    temp=temp->children[key[i]];  
                }else{
                    return false;
                }
            }
            return temp->endOfWord;
        }
    };
    unordered_map<string, bool> memo;

    
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        for(int i=0;i<wordDict.size();i++){
            string curr=wordDict[i];
            trie.insert(curr);
        }
        return helper(s,trie);
    }

    bool helper(string key , Trie &trie){
        if(key.length()==0){
            return true;
        }
        if (memo.count(key)) {
            return memo[key];
        }
        for (int i = 0; i < key.length(); i++) {
            string first = key.substr(0, i + 1);
            string sec = key.substr(i + 1);
            if (trie.search(first) && helper(sec, trie)) {
                return memo[key] = true;
            }
        }
        
        return memo[key] = false;
    }

};