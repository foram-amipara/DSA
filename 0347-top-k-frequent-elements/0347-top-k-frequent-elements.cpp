class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        for (int num : nums) {
            count[num]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> minHeap;

        for (auto& n : count){
            minHeap.push({n.second,n.first});
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }
        vector<int> ans;
        while(!minHeap.empty()){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return ans;

    }
};