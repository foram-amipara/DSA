class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> visited(n, false);
        int components = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;

            components++;
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                for (int j = 0; j < n; j++) {
                    if (!visited[j] &&
                        (stones[curr][0] == stones[j][0] ||
                         stones[curr][1] == stones[j][1])) {
                        visited[j] = true;
                        q.push(j);
                    }
                }
            }
        }

        return n - components;
    }
};