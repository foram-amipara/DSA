class Solution {
public:
//[a,b] = b->a  === u is b and v is a
    bool canFinish(int n, vector<vector<int>>& graph) {
        int V =n;
        vector<bool> vis(V,false);
        vector<bool> rec(V,false);

        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(isCycle(i,rec,vis,graph)){
                    return false;
                }
            }
        } 
        return true;  
    }
    bool isCycle(int src,vector<bool> &rec,vector<bool> &vis,vector<vector<int>>& graph){
        vis[src]=true;
        rec[src]=true;
        for(int i=0;i<graph.size();i++){
            int u=graph[i][1];
            int v=graph[i][0];
            if(src==u){
                if(!vis[v]){
                    if(isCycle(v,rec,vis,graph)){
                        return true;
                    }
                }else{
                    if(rec[v]){
                        return true;
                    }
                }
            }
            

        }
        rec[src]=false;
        return false;
    }
};