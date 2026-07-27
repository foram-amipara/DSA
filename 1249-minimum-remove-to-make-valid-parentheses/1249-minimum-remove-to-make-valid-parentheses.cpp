class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> st;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push({'(', i});
        } else if (s[i] == ')') {
            if (!st.empty() && st.top().first == '(') {
                st.pop();
            } else {
                st.push({')', i});
            }
        }
    }

    unordered_set<int> to_remove;
    while (!st.empty()) {
        to_remove.insert(st.top().second);
        st.pop();
    }

    string result = "";
    for (int i = 0; i < s.length(); i++) {
        if (to_remove.find(i) == to_remove.end()) {
            result += s[i];
        }
    }

    return result;
    }
};

