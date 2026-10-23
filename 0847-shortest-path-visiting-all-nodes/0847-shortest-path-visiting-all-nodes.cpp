class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(1 << n, false));

        for (int i = 0; i < n; i++) {
            int mask = (1 << i);
            q.push({i, mask});
            vis[i][mask] = true;
        }

        int steps = 0;
        int finalMask = (1 << n) - 1;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto [node, mask] = q.front();
                q.pop();

                if (mask == finalMask)
                    return steps;

                for (int nei : graph[node]) {
                    int newMask = mask | (1 << nei);

                    if (!vis[nei][newMask]) {
                        vis[nei][newMask] = true;
                        q.push({nei, newMask});
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};