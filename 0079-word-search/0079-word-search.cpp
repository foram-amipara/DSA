class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        if(word.length()>n*m){
            return false;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(backtrack(board,word,i,j,0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool backtrack(vector<vector<char>>& board, string& word, int i, int j, int idx){
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[idx]) {
            return false;
        }
        if (idx == word.length() - 1) {
            return true;
        }
        char curr = board[i][j];
        board[i][j] = ' ';
        bool found = backtrack(board, word, i + 1, j, idx + 1) || backtrack(board, word, i - 1, j, idx + 1) || backtrack(board, word, i, j + 1, idx + 1) || backtrack(board, word, i, j - 1, idx + 1);
        board[i][j] = curr;
        return found;
    }
};