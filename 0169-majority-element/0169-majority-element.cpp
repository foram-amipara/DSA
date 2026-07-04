class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int currNum;
       int counter;
       for(int i=0;i<nums.size();i++){
            if(counter==0){
                currNum=nums[i];
            }
            if(nums[i]==currNum){
                counter++;
            }else{
                counter--;
            }
       }
       return currNum;
    }
};