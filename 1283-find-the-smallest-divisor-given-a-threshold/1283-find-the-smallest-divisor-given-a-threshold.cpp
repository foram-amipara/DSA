class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxNums = *max_element(nums.begin(), nums.end());
        int ans = binary(nums, maxNums, threshold);
        return ans;
    }

    int binary(vector<int>& nums, int maxNums, int th) {
        int st = 1;
        int end = maxNums;
        int ans = maxNums;

        while (st <= end) {
            int mid = st + (end - st) / 2;
            int divide = checkDiv(mid, nums);

            if (divide <= th) {
                ans = mid;      
                end = mid - 1;  
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }

    int checkDiv(int mid, vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            int curr = nums[i];
            int div = (curr + mid - 1) / mid;
            sum += div;
        }
        return sum;
    }
};