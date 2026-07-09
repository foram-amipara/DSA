class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int left = n - 1;
        int sum = 0;
        int right;
        
        for(right = 0; right < k; right++){
            sum += cardPoints[right];
        }
        int max_score = sum;
        while(right > 0){
            right--;
            sum -= cardPoints[right];
            sum += cardPoints[left];
            left--;
            max_score = max(max_score, sum);
        }
        
        return max_score;
    }
};