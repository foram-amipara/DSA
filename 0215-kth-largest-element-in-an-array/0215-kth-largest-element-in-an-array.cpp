class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;
        for(int i=0;i<nums.size();i++){
            maxHeap.push(nums[i]);
        }
        int count = 0;
        while (!maxHeap.empty() && count < k-1 ) {
            count++;
            maxHeap.pop();
        }
        
        return maxHeap.top();
    }
};