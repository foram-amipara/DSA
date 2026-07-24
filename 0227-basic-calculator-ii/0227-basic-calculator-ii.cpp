class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        long currentNum = 0;
        char op = '+';

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if (isdigit(ch)) {
                currentNum = currentNum * 10 + (ch - '0');
            }

            if ((!isdigit(ch) && ch != ' ') || i == s.length() - 1) {
                if (op == '+') {
                    st.push(currentNum);
                } else if (op == '-') {
                    st.push(-currentNum);
                } else if (op == '*') {
                    int top = st.top();
                    st.pop();
                    st.push(top * currentNum);
                } else if (op == '/') {
                    int top = st.top();
                    st.pop();
                    st.push(top / currentNum);
                }

                op = ch;
                currentNum = 0;
            }
        }

        int result = 0;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};