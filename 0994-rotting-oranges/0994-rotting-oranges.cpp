class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int fresh=0;
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        if(fresh==0){
            return 0;
        }
        int time=0;
        vector<pair<int,int>> dirs={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!q.empty()){
            int sz=q.size();
            bool isRotten=false;
            for(int i=0;i<sz;i++){
                auto[r,c]=q.front();
                q.pop();
                for(auto dir:dirs){
                    int nr=r+dir.first;
                    int nc=c+dir.second;
                    if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1){
                        grid[nr][nc]=2;
                        fresh--;
                        q.push({nr,nc});
                        isRotten=true;
                    }
                }
            }
            if(isRotten){
                time++;
            }
        }
        if(fresh==0){
            return time;
        }
        return -1;
        
    }
    
};