class Solution {
public:
int countGoodNumbers(long long n) {
        long long N = n/2;
        long long ans1,ans2;
        if(n%2==0){
            ans1=solve(5,N);
            ans2=solve(4,N);
        }else{
            ans1=((solve(5,N))*5) % mod;
            ans2=solve(4,N);
        }
        
        return (ans1 * ans2) % mod;
    }
long long mod = 1e9 + 7;

long long solve(long long x, long long n) {
    if (n == 0) return 1;
    
    long long halfPow = solve(x, n / 2);
    long long halfPowSq = (halfPow * halfPow) % mod;
    
    if (n % 2 == 0) {
        return halfPowSq;
    }
    return (x * halfPowSq) % mod;
}
};