#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> prefCount;
        prefCount[0] = 1;
        
        int currSum = 0;
        int count = 0;
        
        for (int num : nums) {
            currSum += num;
            if (prefCount.find(currSum - k) != prefCount.end()) {
                count += prefCount[currSum - k];
            }
            prefCount[currSum]++;
        }
        
        return count;
    }
};