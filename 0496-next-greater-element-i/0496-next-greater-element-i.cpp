class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> next_greater;
        for(int i=0;i<nums2.size();i++){
            while(!s.empty() && s.top()<nums2[i]){
                next_greater[s.top()] = nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }
        vector<int> ans;
        for(int j=0;j<nums1.size();j++){
            if(next_greater.count(nums1[j])){
                ans.push_back(next_greater[nums1[j]]);
            }else{
                ans.push_back(-1);
            }
        }
        return ans;

    }
};