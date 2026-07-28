class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        for(int i = 0; i < operations.size(); i++){
            string curr = operations[i];
            
            if(curr == "C"){
                s.pop();
            } else if(curr == "D"){
                int num = s.top();
                s.push(num * 2);
            } else if(curr == "+"){
                int num1 = s.top();
                s.pop();
                int num2 = s.top();
                s.push(num1);
                s.push(num1 + num2);
            } else {
                s.push(stoi(curr));
            }
        }
        int sum = 0;
        while(!s.empty()){
            sum += s.top();
            s.pop();
        }
        return sum;
    }
};