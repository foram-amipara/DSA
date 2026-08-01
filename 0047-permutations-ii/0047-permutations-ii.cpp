class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>>result;
        backtrack(0,nums,result);
        return result;
    }
    void backtrack(int index,vector<int> &nums,vector<vector<int>>&result){
        if(index==nums.size()){
            result.push_back(nums);
            return;
        }
        unordered_set<int> visited;

        for(int i=index;i<nums.size();i++){
            if (visited.count(nums[i])==1){
                continue;
            } 
            visited.insert(nums[i]);
            swap(nums[index], nums[i]);
            backtrack(index + 1, nums, result);
            swap(nums[index], nums[i]);

        }
    }
};