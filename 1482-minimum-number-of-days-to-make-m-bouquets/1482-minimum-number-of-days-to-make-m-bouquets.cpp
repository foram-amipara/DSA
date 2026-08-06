class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
       if ((long long)m * k > bloomDay.size()) {
            return -1;
        }
        int maxD = *max_element(bloomDay.begin(), bloomDay.end());
        int minD = *min_element(bloomDay.begin(), bloomDay.end());

        return binarySearch(minD, maxD, m, k, bloomDay);
    }
    int checkBouq(int mid, int k, const vector<int>& bloomDay) {
        int bouq = 0;
        int bloomCount = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= mid) {
                bloomCount++;
                if (bloomCount == k) {
                    bouq++;
                    bloomCount = 0; 
                }
            } else {
                bloomCount = 0; 
            }
        }
        return bouq;
    }
    int binarySearch(int minD, int maxD, int m, int k, const vector<int>& bloomDay) {
        int st = minD;
        int end = maxD;
        int ans = -1;

        while (st <= end) {
            int mid = st + (end - st) / 2;
            int totalBouquets = checkBouq(mid, k, bloomDay);
            if (totalBouquets >= m) {
                ans = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }
};