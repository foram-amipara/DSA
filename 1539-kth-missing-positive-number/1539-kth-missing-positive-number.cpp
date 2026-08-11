class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int st=0;
        int end=arr.size()-1;
        while(st<=end){
            int mid = st+(end-st)/2;
            if((arr[mid]-mid-1)>=k){
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        return st+k;
    }
};


// int maxNum=*max_element(arr.begin(),arr.end());
//         int x=maxNum + k;
//         int j=0;
//         int count=0;
//         for(int i=1;i<=x;i++){
//             if(j<arr.size()&&arr[j]==i){
//                 j++;
//                 continue;
//             }else{
//                 count++;
//             }
//             if(count==k){
//                 return i;
//             }
//         }
//         return 0;