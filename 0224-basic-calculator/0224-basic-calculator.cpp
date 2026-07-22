class Solution {
public:
    int calculate(string s) {
        stack<long long> n;
        stack<char> c;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') continue;

            if (s[i] == '+' || s[i] == '-') {
                int j = i - 1;
                while (j >= 0 && s[j] == ' ') j--;
                if (j < 0 || s[j] == '(') {
                    n.push(0);
                }

                while (!c.empty() && c.top() != '(' && n.size() >= 2) {
                    long long a = n.top(); n.pop();
                    long long b = n.top(); n.pop();
                    long long ans = (c.top() == '+') ? (b + a) : (b - a);
                    c.pop();
                    n.push(ans);
                }
                c.push(s[i]);
            } else if (s[i] == '(') {
                c.push(s[i]);
            } else if (s[i] == ')') {
                while (!c.empty() && c.top() != '(' && n.size() >= 2) {
                    long long a = n.top(); n.pop();
                    long long b = n.top(); n.pop();
                    long long ans = (c.top() == '+') ? (b + a) : (b - a);
                    c.pop();
                    n.push(ans);
                }
                if (!c.empty()) c.pop();
            } else if (isdigit(s[i])) {
                long long num = 0;
                while (i < s.length() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                n.push(num);
            }
        }

        while (!c.empty() && n.size() >= 2) {
            long long a = n.top(); n.pop();
            long long b = n.top(); n.pop();
            long long ans = (c.top() == '+') ? (b + a) : (b - a);
            c.pop();
            n.push(ans);
        }

        return n.empty() ? 0 : (int)n.top();
    }
};