class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<pair<int,int>> v;

        for(auto x : intervals) {
            v.push_back({x[0], x[1]});
        }

        sort(v.begin(), v.end(), [](pair<int,int>& a, pair<int,int>& b) {
            return a.second < b.second;
        });

        int count = 0;
        int prevEnd = v[0].second;

        for(int i = 1; i < v.size(); i++) {
            if(v[i].first < prevEnd) {
                count++;
            }
            else {
                prevEnd = v[i].second;
            }
        }

        return count;
    }
};