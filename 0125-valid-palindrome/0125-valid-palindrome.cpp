class Solution {
public:
    bool isPalindrome(string s) {
        string ans;
        for(int i=0;i<s.size();i++){
            int ch=s[i];
            if (ch >= 65 && ch <= 90) {       
                ch = ch + 32;                 
                ans += ch;
            } 
            else if (ch >= 97 && ch <= 122) {
                ans += ch;
            }     
            else if (ch >= 48 && ch <= 57) { 
            ans += ch;
            }
        }
        int n=ans.size();
        int st=0;
        int end=n-1;

        while(st<end){
           
            if(ans[st]!=ans[end]){
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
};