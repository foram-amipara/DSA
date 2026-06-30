class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int low = 0, high = m * n - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            //O(log(m*n))
            int mid_val = matrix[mid / n][mid % n]; 
            
            if (mid_val == target) return true;
            else if (mid_val < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};