class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        string ans="";
        for(int i=0;i<s.length();i++){
            char curr=s[i];
            
            if(curr==']'){
                string str="";
                int num;
                while(!st.empty()&&st.top()!='['){
                    str=st.top()+str;
                    st.pop();
                    
                }
                st.pop();
                string numStr = "";
                while(!st.empty() && isdigit(st.top())) {
                    numStr = st.top() + numStr;
                    st.pop();
                }
                num = stoi(numStr);
                while(num>0){
                    for(char c : str) st.push(c);
                    num--;
                }
                

            }else{
                st.push(curr);
            }
        }
        
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        
        
        
        return ans;
    }
};