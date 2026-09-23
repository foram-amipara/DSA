class Solution {
public:
    struct Node{
        unordered_map<char,Node*> info;
        bool endOfWord;
        Node(){
            endOfWord=false;
        }
    };
    
    struct Trie{
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
};
    unordered_map<string, bool> memo;
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        for(int i=0;i<wordDict.size();i++){
            trie.insert(wordDict[i]); 
        }
        return getAns(trie,s);

    }

    bool getAns(Trie &trie,string s){
        if(s.size()==0){
            return true;
        }
        if(memo.count(s)){
            return memo[s];
        }
        for(int i=0;i<s.length();i++){
            string first=s.substr(0,i+1);
            string second=s.substr(i+1);
            if(trie.search(first) && getAns(trie,second)){
                return memo[s]=true;
            }
        }
        return memo[s]=false;
    }

};