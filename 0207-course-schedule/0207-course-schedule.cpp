class Solution {
public:
    // [a,b] = b->a === u is b and v is a
    bool canFinish(int n, vector<vector<int>>& graph) {
        int V = n;
        vector<bool> vis(V, false);
        vector<bool> rec(V, false);
        vector<vector<int>> adj(V);
        for(int i = 0; i < graph.size(); i++) {
            int u = graph[i][1];
            int v = graph[i][0];
            adj[u].push_back(v);
        }

        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(isCycle(i, rec, vis, adj)) {
                    return false;
                }
            }
        } 
        return true;  
    }

    bool isCycle(int src, vector<bool> &rec, vector<bool> &vis, vector<vector<int>>& adj) {
        vis[src] = true;
        rec[src] = true;

        for(int i = 0; i < adj[src].size(); i++) {
            int v = adj[src][i];

            if(!vis[v]) {
                if(isCycle(v, rec, vis, adj)) {
                    return true;
                }
            } else {
                if(rec[v]) {
                    return true;
                }
            }
        }

        rec[src] = false;
        return false;
    }
};