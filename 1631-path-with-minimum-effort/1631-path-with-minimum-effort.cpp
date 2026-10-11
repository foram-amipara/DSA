class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        
        vector<vector<int>> dist(rows, vector<int>(cols, 1e9));
        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> pq;
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            
            int diff = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if (r == rows - 1 && c == cols - 1) return diff;
            
            for(int i = 0; i < 4; i++) {
                int newR = r + dr[i];
                int newC = c + dc[i];
                
                if(newR >= 0 && newR < rows && newC >= 0 && newC < cols) {
                    int currentEffort = max(diff, abs(heights[newR][newC] - heights[r][c]));
                    if(currentEffort < dist[newR][newC]) {
                        dist[newR][newC] = currentEffort;
                        pq.push({currentEffort, {newR, newC}});
                    }
                }
            }
        }
        
        return 0;
    }
};