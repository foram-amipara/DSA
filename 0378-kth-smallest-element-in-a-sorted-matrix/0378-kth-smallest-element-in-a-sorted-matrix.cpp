class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int n = matrix.size();
        int m = matrix[0].size(); 
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                minHeap.push(matrix[i][j]);
            }
        }
        
        int count = 0;
        while (!minHeap.empty() && count < k - 1) {
            count++;
            minHeap.pop();
        }
        
        return minHeap.top();
    }
};