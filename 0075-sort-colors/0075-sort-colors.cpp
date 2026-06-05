class Solution {
public:
    void sortColors(vector<int>& nums) {
        int freq[3];
        for (int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        for(int i=0,j=0;i<3;i++){
            while(freq[i]>0){
                nums[j]=i;
                j++;
                freq[i]--;
            }
        }

    }
};