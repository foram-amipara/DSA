class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = ff(nums,target);
        int last=fl(nums,target);
        return{first,last};
    }
        private:
        int ff(vector<int>& nums, int target) {
            int n=nums.size();
            int st=0;
            int end =n-1;
            int ans=-1;
            while(st<=end){
                int mid=st+(end-st)/2;
                if(nums[mid]==target){
                    ans=mid;
                    end =mid-1;
                }else if(nums[mid]>target){
                    end=mid-1;
                }else{st=mid+1;}
            }
            return ans;
        }
        int fl(vector<int>& nums, int target) {
            int n=nums.size();
            int st=0;
            int end =n-1;
            int ans=-1;
            while(st<=end){
                int mid=st+(end-st)/2;
                if(nums[mid]==target){
                    ans=mid;
                    st=mid+1;
                }else if(nums[mid]>target){
                    end=mid-1;
                }else{st=mid+1;}
            }
            return ans;
        
        
    }
};