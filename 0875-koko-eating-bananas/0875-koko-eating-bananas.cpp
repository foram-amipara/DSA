class Solution {
public:
    long long hour(vector<int>& piles,int speed){
        long long totalHour = 0;
        for(int i=0;i<piles.size();i++){
            totalHour += (piles[i] + speed - 1) / speed;
        }
        return totalHour;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = *max_element(piles.begin(),piles.end());
        int left=1;
        int right=maxPile;
        int ans =maxPile;
        while(left<=right){
            int mid=(left+right)/2;
            long long totalHour = hour(piles,mid);
            if(totalHour<=h){
                ans=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
       return ans; 
    }
};