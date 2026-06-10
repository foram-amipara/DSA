class Solution {
public:
    bool rotateString(string s, string goal) {
        
        if(s.length()!=goal.length()){
            return false;
        }
        string bigString = s + s ;

        return bigString.find(goal)!= string::npos;
    }
};