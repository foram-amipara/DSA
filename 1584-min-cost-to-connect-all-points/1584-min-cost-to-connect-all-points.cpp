class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int minCost = 0;
        int edgesUsed = 0;
        
        vector<bool> inMST(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0, 0});
        
        while (edgesUsed < n && !pq.empty()) {
            auto p = pq.top();
            pq.pop();
            
            int weight = p.first;
            int u = p.second;
            
            if (inMST[u]) continue;
            
            inMST[u] = true;
            minCost += weight;
            edgesUsed++;
            
            for (int v = 0; v < n; ++v) {
                if (!inMST[v]) {
                    int dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    pq.push({dist, v});
                }
            }
        }
        
        return minCost;
    }
};