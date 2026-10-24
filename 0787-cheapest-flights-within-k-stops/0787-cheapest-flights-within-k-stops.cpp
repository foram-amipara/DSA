class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < flights.size(); i++) {
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        queue<pair<int, pair<int, int>>> q; 
        vector<int> dist(n, INT_MAX);
        
        q.push({0, {src, 0}});
        dist[src] = 0;
        while(q.size() > 0) {
            int stops = q.front().first;
            int u = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();
            if (stops > k) continue;
            
            vector<pair<int, int>> neig = adj[u];
            for(int i = 0; i < neig.size(); i++) {
                int nextNode = neig[i].first;
                int edgeWeight = neig[i].second;
                if(dist[nextNode] > cost + edgeWeight) {
                    dist[nextNode] = cost + edgeWeight;
                    q.push({stops + 1, {nextNode, cost + edgeWeight}});
                }
            }
        }
        
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};