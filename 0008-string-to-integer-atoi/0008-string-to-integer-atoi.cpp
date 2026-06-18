class Solution {
public:
    int parseDigits(const string& s, int i, int sign, long long currentAns) {
        if (i >= s.length() || s[i] < '0' || s[i] > '9') {
            return currentAns * sign;
        }

        int digit = s[i] - '0';
        currentAns = currentAns * 10 + digit;

        if (sign == 1 && currentAns > INT_MAX) return INT_MAX;
        if (sign == -1 && -currentAns < INT_MIN) return INT_MIN;

        return parseDigits(s, i + 1, sign, currentAns);
    }

    int processState(const string& s, int i, int sign, bool processedSign) {
        if (i >= s.length()) return 0;

        if (s[i] == ' ' && !processedSign) {
            return processState(s, i + 1, sign, processedSign);
        }

        if ((s[i] == '+' || s[i] == '-') && !processedSign) {
            int newSign = (s[i] == '-') ? -1 : 1;
            return processState(s, i + 1, newSign, true);
        }

        return parseDigits(s, i, sign, 0);
    }

    int myAtoi(string s) {
        return processState(s, 0, 1, false);
    }
};