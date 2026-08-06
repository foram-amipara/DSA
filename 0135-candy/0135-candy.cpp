class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candyVec(n, 1);

        for (int i = 1; i < n; i++) {
            if (ratings[i - 1] < ratings[i]) {
                candyVec[i] = candyVec[i - 1] + 1;
            }else {
                continue;
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i + 1] < ratings[i]) {
                if (candyVec[i + 1] < candyVec[i]) {
                    continue;
                } else {
                    candyVec[i] = candyVec[i + 1] + 1;
                }
            } else {
                continue;
            }
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += candyVec[i];
        }

        return sum;
    }
};