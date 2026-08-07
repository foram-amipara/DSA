class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int st = newInterval[0];
        int end = newInterval[1];
        vector<vector<int>> ans;
        bool inserted = false;

        for (int i = 0; i < intervals.size(); i++) {
            int currSt = intervals[i][0];
            int currEnd = intervals[i][1];

            if (currEnd < st) {
                ans.push_back(intervals[i]);
            } else if (end < currSt) {
                if (!inserted) {
                    ans.push_back({st, end});
                    inserted = true;
                }
                ans.push_back(intervals[i]);
            } else {
                st = min(st, currSt);
                end = max(end, currEnd);
            }
        }

        if (!inserted) {
            ans.push_back({st, end});
        }

        return ans;
    }
};