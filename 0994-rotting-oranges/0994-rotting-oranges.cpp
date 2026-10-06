class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        queue<pair<int,int>> q;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                } else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        
        if(fresh == 0){
            return 0;
        }
        
        int time = 0;
        
        while(!q.empty()){
            int sz = q.size();
            bool isRotten = false;
            
            for(int i = 0; i < sz; i++){
                auto[r,c] = q.front();
                q.pop();
                
                if (r - 1 >= 0 && grid[r - 1][c] == 1) {
                    grid[r - 1][c] = 2;
                    fresh--;
                    q.push({r - 1, c});
                    isRotten = true;
                }
                if (r + 1 < m && grid[r + 1][c] == 1) {
                    grid[r + 1][c] = 2;
                    fresh--;
                    q.push({r + 1, c});
                    isRotten = true;
                }
                if (c - 1 >= 0 && grid[r][c - 1] == 1) {
                    grid[r][c - 1] = 2;
                    fresh--;
                    q.push({r, c - 1});
                    isRotten = true;
                }
                if (c + 1 < n && grid[r][c + 1] == 1) {
                    grid[r][c + 1] = 2;
                    fresh--;
                    q.push({r, c + 1});
                    isRotten = true;
                }
            }
            
            if(isRotten){
                time++;
            }
        }
        
        if(fresh == 0){
            return time;
        }
        return -1;
    }
};