class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }
        
        unordered_map<int, int> count;
        for (int card : hand) {
            count[card]++;
        }
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto const& [card, freq] : count) {
            minHeap.push(card);
        }
        
        while (!minHeap.empty()) {
            int start = minHeap.top();
            
            if (count[start] == 0) {
                minHeap.pop();
                continue;
            }
            
            for (int i = 0; i < groupSize; ++i) {
                if (count[start + i] == 0) {
                    return false;
                }
                count[start + i]--;
            }
        }
        
        return true;
    }
};