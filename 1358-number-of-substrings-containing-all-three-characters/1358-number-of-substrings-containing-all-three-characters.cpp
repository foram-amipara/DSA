class Solution {
public:
    int numberOfSubstrings(string s) {
        int freq[3]={0};
        int left=0;
        int count=0;
        for(int right=0;right<s.length();right++){
            freq[s[right]-'a']++;
            
            while(freq[s[left]-'a'] > 1){
                freq[s[left]-'a']--;
                left++;
            }
            if(freq[0]>=1&&freq[1]>=1&&freq[2]>=1){
                count+=left+1;
            }
        }
          return count;
    }
    
};