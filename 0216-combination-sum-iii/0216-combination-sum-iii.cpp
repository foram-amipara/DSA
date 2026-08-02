class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        vector<int> nums={1,2,3,4,5,6,7,8,9};
        backtrack(0,k,n,ans,curr,nums);
        return ans;
    }
    void backtrack(int idx,int k,int n,vector<vector<int>> &ans,vector<int> &curr,vector<int> &nums){
        if(k==curr.size()){
            if(n==0){
                ans.push_back(curr);
                return;
            }  
        }
        
        for(int i=idx;i<nums.size();i++){
            if(nums[i]<=n){
                curr.push_back(nums[i]);
                backtrack(i+1,k,n-nums[i],ans,curr,nums);
                curr.pop_back();
            }
        }

    }
};