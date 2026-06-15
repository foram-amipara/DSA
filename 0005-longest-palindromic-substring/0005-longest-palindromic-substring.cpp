class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        int len=0;
        for(int i=0;i<s.length();i++){
            //odd
            int left =i;
            int right =i;
            while(left>=0 && right<s.length() && s[left]==s[right]){
                if((right-left+1)>len){
                    ans=s.substr(left,right-left+1);
                    len=right-left+1;
                }
                left--;
                right++;
            }

            //even
            left=i;
            right=i+1;
            while(left>=0&&right<s.length()&&s[left]==s[right]){
                if((right-left+1)>len){
                    ans=s.substr(left,right-left+1);
                    len=right-left+1;
                }
                left--;
                right++;
            }
        }
 
        return ans;
    }
};