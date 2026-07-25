class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
        vector<int> rm(n,0);
        vector<int> lm(n,0);
        stack<int> s; 

        lm[0]=height[0];
        rm[n-1]=height[n-1];

        s.push(height[0]);
        //lm
        for(int i=1;i<n;i++){
            int curr=height[i];
            if (height[i] > s.top()) {
            s.pop();
            s.push(height[i]);
            }
            lm[i] = s.top();
        }
        while(!s.empty()){
            s.pop();
        }
        s.push(height[n-1]);

        for (int i = n - 2; i >= 0; i--) {
            if (height[i] > s.top()) {
                s.pop();
                s.push(height[i]);
            }
            rm[i] = s.top();
        }
       
        int water=0;
        for(int i=0;i<n;i++){
            int currWater = min(lm[i],rm[i])-height[i];
            if(currWater>0){
                water+=currWater;
            }
        }
        return water;
    }
};




// int n= height.size();
//         int rightMax[n];
//         int leftMax[n];
//         leftMax[0]=height[0];
//         rightMax[n-1]=height[n-1];
//         //left max
//         for(int i=1;i<n;i++){
//             leftMax[i]=max(leftMax[i-1],height[i-1]);
//         }
//         //right max
//         for(int i=n-2;i>=0;i--){
//             rightMax[i]=max(rightMax[i+1],height[i+1]);
//         }
//         int water=0;
//         for(int i=0;i<n;i++){
//             int currWater = min(leftMax[i],rightMax[i])-height[i];
//             if(currWater>0){
//                 water+=currWater;
//             }
//         }
//         return water;