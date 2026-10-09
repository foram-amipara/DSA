class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int n=graph.size();
        vector<vector<int>> reverse(n);
        vector<int> inDeg(n,0);

        for(int i=0;i<n;i++){
            for(int v:graph[i]){
                reverse[v].push_back(i);
            }
            inDeg[i]=graph[i].size();
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(inDeg[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int v=q.front();
            q.pop();
            ans.push_back(v);
            for(int neig:reverse[v]){
                inDeg[neig]--;
                if(inDeg[neig]==0){
                    q.push(neig);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;

    }
};