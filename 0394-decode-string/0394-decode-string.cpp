class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        stack<char> rev;
        string ans="";
        for(int i=0;i<s.length();i++){
            char curr=s[i];
            
            if(curr==']'){
                string str="";
                int num;
                while(!st.empty()&&st.top()!='['){
                    rev.push(st.top());
                    st.pop();
                    
                }
                while(!rev.empty()){
                    str+=rev.top();
                    rev.pop();
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
            rev.push(st.top());
            st.pop();
        }
        while(!rev.empty()){
            ans+=rev.top();
            rev.pop();
        }
        
        
        return ans;
    }
};