class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        
        if (k == 0) return;
        
        vector<int> temp(n);
        
        
        for (int j = n - 1; j >= 0; j--) {
            int num = nums[j]; 
            int new_position = (j + k) % n;
            temp[new_position] = num;
        }
        
        nums = temp;
    }
};