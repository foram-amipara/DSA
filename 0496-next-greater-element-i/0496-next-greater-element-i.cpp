class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        stack<int> s;
        unordered_map<int, int> ngr;

        ngr[nums2[n - 1]] = -1;
        s.push(nums2[n - 1]);

        for (int i = n - 2; i >= 0; i--) {
            int curr = nums2[i];

            while (!s.empty() && curr >= s.top()) {
                s.pop();
            }

            if (s.empty()) {
                ngr[curr] = -1;
            } else {
                ngr[curr] = s.top();
            }

            s.push(curr);
        }

        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(ngr[nums1[i]]);
        }

        return ans;
    }
};