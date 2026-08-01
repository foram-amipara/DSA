class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(0,target,curr,candidates,ans);
        return ans;

    }
    void backtrack(int idx, int target,vector<int> &curr,vector<int> &candidates,vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(curr);
            return;
        }
        if(target<0||idx==candidates.size()){
            return;
        }
        if(candidates[idx]<=target){
            curr.push_back(candidates[idx]);
            backtrack(idx+1,target-candidates[idx],curr,candidates,ans);
            curr.pop_back();
        }
        int nextIdx=idx+1;
        while(nextIdx<candidates.size()&&candidates[nextIdx]==candidates[idx]){
            nextIdx++;
        }
        backtrack(nextIdx,target,curr,candidates,ans);

    }
};