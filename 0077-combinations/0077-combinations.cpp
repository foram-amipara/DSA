class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums(n); 
        iota(nums.begin(), nums.end(), 1); 
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(0,k,nums,curr,ans);
        return ans;
    }
    void backtrack(int idx ,int k, vector<int>&nums,vector<int>&curr,vector<vector<int>> &ans){
        if(curr.size()==k){
            ans.push_back(curr);
            return;
        }
        for(int i=idx;i<nums.size();i++){
            curr.push_back(nums[i]);
            backtrack(i+1,k,nums,curr,ans);
            curr.pop_back();
        }
    }
};