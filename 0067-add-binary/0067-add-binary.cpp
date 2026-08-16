class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length() - 1;
        int j = b.length() - 1;
        string ans = "";
        int carry = 0;
        
        while(i >= 0 || j >= 0 || carry == 1) {
            int sum = carry;
            if(i >= 0) {
                sum += a[i] - '0'; // '0'-'0' = 0, '1'-'0' = 1
                i--;
            }
            if(j >= 0) {
                sum += b[j] - '0';
                j--;
            }
            ans.push_back((sum % 2) ? '1' : '0');
            carry = sum / 2;
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};