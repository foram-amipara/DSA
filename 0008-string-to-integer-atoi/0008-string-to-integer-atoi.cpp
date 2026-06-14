class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int n=s.length();
        int ans=0;
        int sign=1;

        while(i<n && s[i]==' '){
            i++;
        }

        if(i<n && (s[i]=='+' || s[i]=='-' )){
            sign = (s[i]=='-')?-1:1;
            i++;
        }

        while(i<n && s[i]>='0' && s[i]<='9'){
            int digit =s[i]-'0';
            if(ans>INT_MAX/10 || (ans == INT_MAX/10 && digit>INT_MAX%10)){
                return (sign == 1)? INT_MAX:INT_MIN;
            }
            ans=ans*10+digit;
            i++;
        }
        return ans*sign;
    }
};