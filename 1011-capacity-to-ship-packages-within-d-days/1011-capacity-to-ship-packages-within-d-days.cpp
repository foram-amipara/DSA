class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int sum = 0;
        for (int i = 0; i < weights.size(); i++) {
            sum += weights[i];
        }
        int high = sum;
        return binary(weights, days, low, high);
    }

    int countDays(vector<int>& weights, int cap) {
        int daysNeeded = 1;
        int currentWeight = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (currentWeight + weights[i] > cap) {
                daysNeeded++;
                currentWeight = 0;
            }
            currentWeight += weights[i];
        }
        return daysNeeded;
    }

    int binary(vector<int>& weights, int days, int low, int high) {
        int st = low;
        int end = high;
        int ans = high;

        while (st <= end) {
            int mid = st + (end - st) / 2;
            int daysNeeded = countDays(weights, mid);

            if (daysNeeded <= days) {
                ans = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }
};