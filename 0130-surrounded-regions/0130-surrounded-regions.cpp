class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    vector<pair<int,int>> space;
                    if(dfs(board,i,j,m,n,space)){
                        for(auto& [r,c] : space){
                            board[r][c]='X';
                        }
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='#'){
                    board[i][j]='O';
                }
            }
        }

    }
    bool dfs(vector<vector<char>>& board,int r,int c,int m,int n,vector<pair<int,int>> &space){
        if(r<0 || c<0 || r>=m || c>=n ){
            return false;
        }
        if(board[r][c]=='X' || board[r][c]=='#'){
            return true;
        }
        board[r][c]='#';
        space.push_back({r,c});

        bool down  = dfs(board, r + 1, c, m, n, space);
        bool up    = dfs(board, r - 1, c, m, n, space);
        bool right = dfs(board, r, c + 1, m, n, space);
        bool left  = dfs(board, r, c - 1, m, n, space);

        return down && up && right && left;
    }
};