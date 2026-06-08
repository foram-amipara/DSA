class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int st=0;
        int end=n-1;
       while(st<end){
            if(nums[st]==nums[st+1]){
                st+=2;
            }
            if(nums[end]==nums[end-1]){
                end-=2;
            }
        }
        return nums[st];
    }
};