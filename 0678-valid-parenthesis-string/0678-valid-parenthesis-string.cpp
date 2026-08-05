class Solution {
public:
    bool checkValidString(string s) {
        int n=s.length();
        int countOpen=0;
        int countClose=0;
        int countStar=0;

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                countOpen++;
            }else if(s[i]==')'){
                countClose++;
            }else{
                countStar++;
            }
            if(countClose > countOpen + countStar) return false;
        }

        countOpen=0;
        countClose=0;
        countStar=0;

        for(int i=n-1;i>=0;i--){
            if(s[i]=='('){
                countOpen++;
            }else if(s[i]==')'){
                countClose++;
            }else{
                countStar++;
            }
            if(countOpen > countClose + countStar) return false;
        }

        return true;
    }
};