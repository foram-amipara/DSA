class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int st=0;
        int mid=0;
        int end=n-1;

        while(end>=mid){
            if(nums[mid]==0){
                swap(nums[st],nums[mid]);
                st++;
                mid++;
            }
            else if(nums[mid]==2){
                swap(nums[end],nums[mid]);
                end--;
                
            }else{
                mid++;
            }
            
        }


        // int freq[3];
        // for (int i=0;i<nums.size();i++){
        //     freq[nums[i]]++;
        // }
        // for(int i=0,j=0;i<3;i++){
        //     while(freq[i]>0){
        //         nums[j]=i;
        //         j++;
        //         freq[i]--;
        //     }
        // }

    }
};