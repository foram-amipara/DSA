class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        for (int i = 0; i < m; i++) {
            int st = 0;
            for (int j = 1; j < n; j++) {
                if (mat[i][j] > mat[i][st]) {
                    st = j;
                }
            }
            int top = (i > 0) ? mat[i - 1][st] : -1;
            int bottom = (i + 1 < m) ? mat[i + 1][st] : -1;
            
            if (mat[i][st] > top && mat[i][st] > bottom) {
                return {i, st};
            }
        }
        
        return {-1, -1};
    }
};