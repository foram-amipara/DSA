class Solution {
public:
    int maxDepth(string s) {
        int count=0;
        int maxCount=0;
        for(int i=0;i<s.length();i++){
            if(s[i]!='('&& s[i]!=')'){
                continue;
            }
            if(s[i]=='('){
                count++;
            }else{
                maxCount=max(maxCount,count);
                count--;
            }
        }
        return maxCount;
    }
};