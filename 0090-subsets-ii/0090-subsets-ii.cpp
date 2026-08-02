class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        backtrack(0,nums,curr,ans);
        return ans;
    }
    void backtrack(int idx,vector<int> &nums,vector<int> &curr,vector<vector<int>> &ans){
        
        ans.push_back(curr);
           
        for(int i=idx;i<nums.size();i++){
            if (i > idx && nums[i] == nums[i - 1]) continue;
            curr.push_back(nums[i]);
            backtrack(i+1,nums,curr,ans);
            curr.pop_back();
        }
    }
};