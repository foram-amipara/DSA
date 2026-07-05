class Solution {
public:

vector<string> generateParenthesis(int n) {
    vector<string> res;
    genAns("", 0, 0, n, res);
    return res;
}
 void genAns(string curr, int open, int close, int n, vector<string>& res) {
    if (curr.length() == 2 * n) {
        res.push_back(curr);
        return;
    }
    if (open < n){
        genAns(curr + '(', open + 1, close, n, res);
    } 
    if (close < open){
        genAns(curr + ')', open, close + 1, n, res);
    } 
}

    
};