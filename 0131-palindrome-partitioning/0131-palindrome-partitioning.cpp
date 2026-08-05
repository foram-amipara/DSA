class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        backtrack(0, ans, curr, s);
        return ans;
    }
    void backtrack(int idx, vector<vector<string>> &ans, vector<string> &curr, string s) {
        if (idx == s.length()) {
            ans.push_back(curr);
            return;
        }
        for (int i = idx; i < s.length(); i++) {
            if (isPalindrome(s, idx, i)) {
                curr.push_back(s.substr(idx, i - idx + 1));
                backtrack(i + 1, ans, curr, s);
                curr.pop_back();
            }
        }
    }
    bool isPalindrome(const string &s, int st, int end) {
        while (st <= end) {
            if (s[st] != s[end]) {
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
};