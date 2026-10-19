class Solution {
public:
    static int countBits(int n) {
        int count = 0;
        while (n > 0) {
            count += n % 2;
            n /= 2;
        }

        return count;
    }
    static bool comp(int a, int b) {
        int x = countBits(a);
        int y = countBits(b);

        if (x == y) {
            return a < b;
        }
        return x < y;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), comp);
        return arr;
    }
};