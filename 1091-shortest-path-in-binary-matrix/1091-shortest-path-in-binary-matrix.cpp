class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0){
            return -1;
        }
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;

        int i[]={-1,-1,-1,0,0,1,1,1};
        int j[]={-1,0,1,-1,1,-1,0,1};
        int ans=1;
        while(!q.empty()){
            int sz=q.size();
            for(int k=0;k<sz;k++){
                auto[r,c]=q.front();
                q.pop();
                if(r==n-1 && c==n-1){
                    return ans;
                }
                for(int dir=0;dir<8;dir++){
                    int newR=r+i[dir];
                    int newC=c+j[dir];
                    if (newR >= 0 && newR < n && newC >= 0 && newC < n && grid[newR][newC] == 0) {
                        q.push({newR, newC});
                        grid[newR][newC] = 1;
                    }

                }
            }
            ans++;

        }
        return -1;

    }
};