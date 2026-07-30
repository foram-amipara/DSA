class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }

private:
    long long sumSubarrayMins(const vector<int>& arr) {
        int n = arr.size();
        vector<int> nsl(n), nsr(n);
        stack<int> s;
        //nsr
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            if(s.empty()){
                nsr[i]=n;
            }else{
                nsr[i]=s.top();
            }
            s.push(i);
        }

        while (!s.empty()) s.pop();
        //nsl
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }
            if(s.empty()){
                nsl[i]=-1;
            }else{
                nsl[i]=s.top();
            }
            s.push(i);
        }

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - nsl[i];
            long long right = nsr[i] - i;
            sum += left * right * arr[i];
        }

        return sum;
    }

    long long sumSubarrayMaxs(const vector<int>& arr) {
        int n = arr.size();
        vector<int> ngl(n), ngr(n);
        stack<int> s;
        //ngr
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] <= arr[i]) {
                s.pop();
            }
            if(s.empty()){
                ngr[i]=n;
            }else{
                ngr[i]=s.top();
            }
            s.push(i);
        }
        //ngl
        while (!s.empty()) s.pop();

        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] < arr[i]) {
                s.pop();
            }
            if(s.empty()){
                ngl[i]=-1;
            }else{
                ngl[i]=s.top();
            }
            s.push(i);
        }

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - ngl[i];
            long long right = ngr[i] - i;
            sum += left * right * arr[i];
        }

        return sum;
    }
};