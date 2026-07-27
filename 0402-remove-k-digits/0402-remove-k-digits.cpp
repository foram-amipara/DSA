class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        stack<char> s;
        int n=num.length();
        for(int i=0;i<n;i++){
            char curr=num[i];
            while(!s.empty() && k>0 && curr<s.top()){
                k--;
                s.pop();
            }
            s.push(curr);
        }
        while(!s.empty() && k>0){
            s.pop();
            k--;
        }
        while (!s.empty()) {
            ans += s.top(); 
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        int i;
        for(i=0;i<ans.length();i++){
            if(ans[i]!='0'){
                break;
            }
        }
        ans = ans.substr(i);
        
        if(ans==""){
            return "0";
        }else{
            return ans;
        }
        
    }
};