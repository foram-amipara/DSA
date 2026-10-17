class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);
        vector<int> vis(V, false);
        for (int i = 0; i < V; ++i) {
            if (color[i] != -1) continue; 
            queue<int> q;
            q.push(i);
            color[i] = 0;

            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                for (int neig : graph[curr]) {
                    if (!vis[neig]) {
                        vis[neig]=true;
                        color[neig] = !color[curr]; 
                        q.push(neig);
                    } else if (color[neig] == color[curr]) {
                        return false; 
                    }
                }
            }
        }

        return true;
    }
};