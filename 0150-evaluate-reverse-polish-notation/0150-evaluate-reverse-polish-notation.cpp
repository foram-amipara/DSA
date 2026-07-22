class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                int ans = b + a;
                s.push(ans);
            } else if(tokens[i] == "-"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                int ans = b - a;
                s.push(ans);
            } else if(tokens[i] == "*"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                int ans = b * a;
                s.push(ans);
            } else if(tokens[i] == "/"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                int ans = b / a;
                s.push(ans);
            } else {
                int curr = stoi(tokens[i]);
                s.push(curr);
            }
        }
        return s.top();
    }
};