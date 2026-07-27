class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        vector<int> ans;

        for (int i = 0; i < asteroids.size(); i++) {
            int curr = asteroids[i];
            bool nextPop = false;

            while (!s.empty() && s.top() > 0 && curr < 0) {
                if (abs(s.top()) < abs(curr)) {
                    s.pop();
                }
                else if (abs(s.top()) == abs(curr)) {
                    s.pop();
                    nextPop = true;
                    break;
                }
                else {
                    nextPop = true;
                    break;
                }
            }

            if (!nextPop) {
                s.push(curr);
            }
        }

        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};