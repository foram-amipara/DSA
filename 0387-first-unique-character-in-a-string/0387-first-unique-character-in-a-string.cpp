class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26]={0};
        queue<pair<char,int>> q;

        for(int i=0;i<s.length();i++){
            char curr=s[i];
            freq[curr-'a']++;
            q.push({curr,i});
            while(!q.empty() && freq[q.front().first-'a']>1){
                q.pop();
            }
        }
        if(q.empty()){
            return -1;
        }
        return q.front().second;
    }
};