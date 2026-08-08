class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int st1=m-1;
        int st2=n-1;
        int merge=m+n-1;
        while(st1 >= 0 && st2 >= 0){
            if(nums1[st1]>nums2[st2]){
                nums1[merge] = nums1[st1];
                st1--;
            }else{
                nums1[merge] = nums2[st2];
                st2--;
            }
            merge--;
        }
        while(st2 >= 0) {
            nums1[merge] = nums2[st2];
            st2--;
            merge--;
        }
    }
};