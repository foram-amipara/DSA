class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ptr1 = 0;
        for (int ptr2 = 0; ptr2 < nums.size(); ptr2++) {
            if (nums[ptr2] != val) {
                nums[ptr1] = nums[ptr2];
                ptr1++;
            }
        }
        return ptr1;
    }
};