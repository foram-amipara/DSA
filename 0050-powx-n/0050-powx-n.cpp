class Solution {
private:
    double solve(double x, long long n) {
        if (n == 0) return 1.0;
        
        double halfPow = solve(x, n / 2);
        double halfPowSq = halfPow * halfPow;
        
        if (n % 2 != 0) {
            return x * halfPowSq;
        }
        
        return halfPowSq;
    }

public:
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        return solve(x, N);
    }
};