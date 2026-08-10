class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int maxNum=*max_element(arr.begin(),arr.end());
        int x=maxNum + k;
        int j=0;
        int count=0;
        for(int i=1;i<=x;i++){
            if(j<arr.size()&&arr[j]==i){
                j++;
                continue;
            }else{
                count++;
            }
            if(count==k){
                return i;
            }
        }
        return 0;
    }
};