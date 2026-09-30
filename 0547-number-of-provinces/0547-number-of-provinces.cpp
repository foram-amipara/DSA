class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool> vis(n,false);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,isConnected,vis ,n);
                ans++;
            }
        }
        return ans;
    }
    void dfs(int i,vector<vector<int>>& isConnected,vector<bool>& vis,int n){
        vis[i]=true;
        for(int j=0;j<n;j++){
            if(isConnected[i][j]==1 && !vis[j]){
                dfs(j,isConnected,vis,n);
            }
        }
    }
};