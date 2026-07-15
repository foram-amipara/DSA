class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int j=0;
        int maxlen=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=1){
                j=i+1;
            }
            maxlen = max(i-j+1,maxlen);
        }
        return maxlen;
    }
};