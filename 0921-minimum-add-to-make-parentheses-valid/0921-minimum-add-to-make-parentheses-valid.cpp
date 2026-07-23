class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int count=0;
        for(int i=0;i<s.length();i++){
            char curr=s[i];
            if(curr==')'){
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }else{st.push(curr);}
            }else{
                st.push(curr);
            }
        }
        while(!st.empty()){
            count++;
            st.pop();
        }
        return count;
    }
};