class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<int> sandwich;
        queue<int> stud;
        int n=students.size();
        int count=0;
        for(int i=sandwiches.size()-1;i>=0;i--){
            int curr=sandwiches[i];
            sandwich.push(curr);
        }
        for(int i=0;i<sandwiches.size();i++){
            int curr=students[i];
            stud.push(curr);
        }
        while(!stud.empty()|| !sandwich.empty()){
            if(sandwich.top()==stud.front()){
                stud.pop();
                sandwich.pop();
                count=0;
            }else{
                int student=stud.front();
                stud.pop();
                stud.push(student);
                count++;
            }
            if(count==n){
                return stud.size();
            }
        }
        return count;
    }
};