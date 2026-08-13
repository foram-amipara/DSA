class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int comp = target - nums[i];
            if(m.count(comp)){
                ans.push_back(i);
                ans.push_back(m[comp]);
            }
            m[nums[i]]=i;
        }
        return ans;
    }
};

// for(int i = 0; i < nums.size(); i++) {
//             for(int j = i + 1; j < nums.size(); j++) {
//                 if(nums[i] + nums[j] == target) {
//                     return {i, j};
//                 }
//             }
//         }
//         return {};