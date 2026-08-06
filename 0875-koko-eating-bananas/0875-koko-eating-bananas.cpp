class Solution {
public:
    long long checkSpeed(int k, const std::vector<int>& piles) {
        long long currH = 0;
        for (int i = 0; i < piles.size(); i++) {
            int curr = piles[i];
            if (curr <= k) {
                currH++;
            } else {
                currH += curr / k;
                if (curr % k != 0) {
                    currH++;
                }
            }
        }
        return currH;
    }

    int binarySearch(int maxSpeed, int h, const std::vector<int>& piles) {
        int st = 1;
        int end = maxSpeed;
        int ans = maxSpeed;

        while (st <= end) {
            int mid = st + (end - st) / 2;
            long long currH = checkSpeed(mid, piles);

            if (currH <= h) {
                ans = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }

    int minEatingSpeed(std::vector<int>& piles, int h) {
        int maxSpeed = *std::max_element(piles.begin(), piles.end());
        return binarySearch(maxSpeed, h, piles);
    }
};




// long long hour(vector<int>& piles,int speed){
//         long long totalHour = 0;
//         for(int i=0;i<piles.size();i++){
//             totalHour += (piles[i] + speed - 1) / speed;
//         }
//         return totalHour;
//     }

//     int minEatingSpeed(vector<int>& piles, int h) {
//         int maxPile = *max_element(piles.begin(),piles.end());
//         int left=1;
//         int right=maxPile;
//         int ans =maxPile;
//         while(left<=right){
//             int mid=(left+right)/2;
//             long long totalHour = hour(piles,mid);
//             if(totalHour<=h){
//                 ans=mid;
//                 right=mid-1;
//             }else{
//                 left=mid+1;
//             }
//         }
//        return ans; 
//     }