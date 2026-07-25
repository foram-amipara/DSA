class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            char curr = s[i];
            
            if (!st.empty() && curr == st.top()) { 
                st.pop();
            } else {
                st.push(curr);
            }
        }

        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};