class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int count = 0;
        int currEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= currEnd) {
                currEnd = intervals[i][1];
            } else {
                count++;
            }
        }

        return count;
    }
    
};


static bool compare(const pair<int, int> &p1, const pair<int, int> &p2) {
        return p1.second < p2.second;
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        int n = intervals.size();
        vector<pair<int, int>> pairs(n);
        
        for (int i = 0; i < n; i++) {
            pairs[i] = make_pair(intervals[i][0], intervals[i][1]);
        }

        sort(pairs.begin(), pairs.end(), compare);

        int count = 0;
        int currEnd = pairs[0].second;

        for (int i = 1; i < n; i++) {
            if (pairs[i].first >= currEnd) {
                
                currEnd = pairs[i].second; 
            } else {
                count++;
            }
        }

        return count;
    }