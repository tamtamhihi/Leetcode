/*
https://leetcode.com/problems/robot-collisions/

Sort the robots by position (keep the original index).

Then use a stack to solve:
- If we see a robot moving "R" direction => not likely to collide with any robots already in the stack (on its left) => just push to stack
- Otherwise, an "L" robot => likely to collide with previous "R" robots in the stack
  + We pop these robots from the top of stack until no "R" robots left or current "L" robot is destroyed
*/

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<pair<int, int>> posWithIdx(n);
        for (int i = 0; i < n; ++i) {
            posWithIdx[i] = make_pair(positions[i], i);
        }
        sort(posWithIdx.begin(), posWithIdx.end());

        stack<int> idx;
        vector<int> results = vector<int>(healths);

        for (int k = 0; k < n; ++k) {
            auto robot = posWithIdx[k];
            if (directions[robot.second] == 'R') {
                idx.push(robot.second);
            } else {
                bool isDestroyed = false;
                int l = robot.second;
                while (!isDestroyed && !idx.empty() && directions[idx.top()] == 'R') {
                    int r = idx.top();
                    if (results[r] == results[l]) {
                        // destroy "R" robot
                        results[r] = -1;
                        idx.pop();
                        // destroy "L" robot
                        results[l] = -1;
                        isDestroyed = true;
                    } else if (results[r] < results[l]) {
                        // destroy "R" robot
                        results[r] = -1;
                        idx.pop();
                        // weaken "L" robot
                        results[l] -= 1;
                    } else {
                        // weaken "R" robot
                        results[r] -= 1;
                        // destroy "L" robot
                        results[l] = -1;
                        isDestroyed = true;
                    }
                }
                if (!isDestroyed) {
                    idx.push(l);
                }
            }
        }
        vector<int> answer;
        for (int i = 0; i < n; ++i) {
            if (results[i] != -1) {
                answer.push_back(results[i]);
            }
        }
        return answer;
    }
};
