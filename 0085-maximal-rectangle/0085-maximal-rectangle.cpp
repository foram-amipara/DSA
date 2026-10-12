class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()||matrix[0].empty()){
            return 0;
        }
        int m=matrix.size();
        int n=matrix[0].size();
        int ans=0;
        vector<int> height(n,0);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                    height[j]++;
                }else{
                    height[j]=0;
                }
            }
            ans=max(ans,largestRec(height));
        }
        return ans;
    }
    int largestRec(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        int maxArea = 0;
        for (int i = 0; i <= n; ++i) {
            while (!s.empty() && (i == n || heights[s.top()] >= heights[i])) {
                int h = heights[s.top()];
                s.pop();
                int w = s.empty() ? i : i - s.top() - 1;
                maxArea = max(maxArea, h * w);
            }
            s.push(i);
        }
        return maxArea;
    }

};