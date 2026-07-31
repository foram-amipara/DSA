class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(0,candidates,curr,target,ans);
        return ans;
    }

    void backtrack(int idx,vector<int>& candidates,vector<int>& curr,int target,vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(curr);
            return;
        }
        if(idx==candidates.size()||target<0){
            return;
        }
        if(candidates[idx]<=target){
            curr.push_back(candidates[idx]);
            backtrack(idx,candidates,curr,target-candidates[idx],ans);
            curr.pop_back();
        }
        backtrack(idx+1,candidates,curr,target,ans);

    }
    
};