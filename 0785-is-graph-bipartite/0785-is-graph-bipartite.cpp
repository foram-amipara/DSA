class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);

        for (int i = 0; i < V; ++i) {
            if (color[i] != -1) continue; 
            queue<int> q;
            q.push(i);
            color[i] = 0;

            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                for (int neig : graph[curr]) {
                    if (color[neig] == -1) {
                        color[neig] = 1 - color[curr]; 
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