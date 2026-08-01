class Solution {
public:
    void backtrack(int idx, int target, vector<int>& curr, vector<int>& candidates, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            if (i > idx && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] > target) break;

            curr.push_back(candidates[i]);
            backtrack(i + 1, target - candidates[i], curr, candidates, ans);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(0, target, curr, candidates, ans);
        return ans;
    }
};