class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int n=prices.size();
        // int bestBuy[n];
        // bestBuy[0]=INT_MAX;
        
        // for(int i=1;i<n;i++){
        //     bestBuy[i]=min(prices[i-1],bestBuy[i-1]);
        // } 
        // int profit =0; 
        // for(int i=0;i<n;i++){
        //     int currProfit = prices[i]-bestBuy[i];
        //     profit = max(profit,currProfit);
        // }
        // return profit;
        int right = 0;
        int left = 0;
        int ans = 0; 
        
        while(right < prices.size()){
            if(prices[left] > prices[right]){
                left = right;
            } else {
                ans = max(ans, prices[right] - prices[left]);
            }
            right++;
        }
        
        return ans;
    }
};