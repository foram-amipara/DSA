class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int targetMask = (1 << n) - 1;
        queue<vector<int>> q;
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false));

        for (int i = 0; i < n; i++) {
            q.push({i, 1 << i, 0});
            visited[i][1 << i] = true;
        }

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int node = curr[0];
            int mask = curr[1];
            int dist = curr[2];

            if (mask == targetMask) return dist;

            for (int neighbor : graph[node]) {
                int nextMask = mask | (1 << neighbor);
                if (!visited[neighbor][nextMask]) {
                    visited[neighbor][nextMask] = true;
                    q.push({neighbor, nextMask, dist + 1});
                }
            }
        }

        return 0;
    }
};