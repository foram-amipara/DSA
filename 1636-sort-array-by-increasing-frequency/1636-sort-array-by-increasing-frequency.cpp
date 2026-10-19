class Solution {
public:
    static unordered_map<int, int> freq;

    static bool comp(int a, int b) {
        if (freq[a] == freq[b]) {
            return a > b;
        }
        return freq[a] < freq[b];
    }
    vector<int> frequencySort(vector<int>& nums) {
        freq.clear();

        for (int num : nums) {
            freq[num]++;
        }

        sort(nums.begin(), nums.end(), comp);

        return nums;
    }
};
unordered_map<int, int> Solution::freq;
