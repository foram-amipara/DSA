class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int ans=0;
        int maxFreq=0;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            maxFreq=max(maxFreq,mp[nums[i]]);
        }
        for(auto it: mp){
            if(it.second==maxFreq){
                ans+= it.second;
            }
        }
        return ans;
    }
};