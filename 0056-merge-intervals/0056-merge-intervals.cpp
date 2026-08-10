class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= ans.back()[1]) {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         vector<vector<int>> ans;
//         vector<pair<int,int>> pairs(intervals.size());
//         for(int i=0;i<intervals.size();i++){
//             pairs[i]=make_pair(intervals[i][0],intervals[i][1]);
//         }
//         getAns(pairs,ans);
//         return ans;

//     }
//     void getAns(vector<pair<int,int>> &pairs,vector<vector<int>> &ans){
//         if(pairs.empty()) return;
//         int n=pairs.size();
//         sort(pairs.begin(),pairs.end(),compare);
//         int currEnd=pairs[0].second;
//         int currSt=pairs[0].first;

//         for(int i=1;i<n;i++){
//             if(pairs[i].first<=currEnd){
//                 currEnd=max(currEnd,pairs[i].second);
//             }else{
//                 ans.push_back({currSt,currEnd});
//                 currSt=pairs[i].first;
//                 currEnd=pairs[i].second;
//             }
//         }
//         ans.push_back({currSt,currEnd});

//     }
//     static bool compare(const pair<int,int> &p1,pair<int,int> &p2){
//         return p1.first<p2.first;
//     }
// };