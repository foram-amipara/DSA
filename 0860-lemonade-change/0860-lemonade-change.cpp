class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        int count5=0;
        int count10=0;
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                count5++;
            }else if(bills[i]==10){
                count5--;
                count10++;
                if(count5<0 || count10<0) return false;
            }else{
                if(count10 && count5){
                    count10--;
                    count5--;
                    if(count5<0 || count10<0) return false;
                }else{
                    count5-=3;
                    if(count5<0 || count10<0) return false;
                }
            }
        }
        return (count5>=0 && count10>=0);
    }
};