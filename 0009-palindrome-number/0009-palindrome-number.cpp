class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        long long ans=0;
        int lastDig=0;
        int copy=x;
        
        while(copy>0){
            lastDig=copy%10;
            ans=(ans*10)+lastDig;
            copy/=10;
        }
        if(ans==x){
            return true;
        }
        return false;
    }
};