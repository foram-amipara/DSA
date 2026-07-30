class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        stack<int> s;
        int nsl[n];
        int nsr[n];
        const int MOD = 1e9 + 7;
        //nsr
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()] >= arr[i]){
                s.pop();
            }
            if(s.empty()){
                nsr[i]=n;
            }else{
                nsr[i]=s.top();
            }
            s.push(i);
        }

        while(!s.empty()){
            s.pop();
        }

        //nsl
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()]>arr[i]){
                s.pop();
            }
            if(s.empty()){
                nsl[i]=-1;
            }else{
                nsl[i]=s.top();
            }
            s.push(i);
        }


        long long sum=0;
        for(int i=0;i<n;i++){
            long long x=i-nsl[i];
            long long y=nsr[i]-i;
            long long totalArr=(x*y)%MOD;
            long long contribution = (totalArr * arr[i])%MOD;
            sum = (sum + contribution) % MOD;
        }
        return sum;

    }
};