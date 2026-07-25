class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        int n=temperatures.size();
        s.push(n-1);
        vector<int> ans(n,0);
        
        for(int i=n-2;i>=0;i--){
            int curr = temperatures[i];
            while(!s.empty() && curr>=temperatures[s.top()]){
                s.pop();
            }
            if(!s.empty()){
                ans[i]=s.top()-i;
            }else{
                ans[i]=0;
            }
            s.push(i);
        }
        return ans;
    }
};