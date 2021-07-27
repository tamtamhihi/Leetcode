class Solution {
public:
    int findRotateSteps(string ring, string key) {
        // For each character, map it to the list of indices 
        // in ring with this character.
        unordered_map<char, vector<int>> m;
        for (int i = 0; i < ring.size(); ++i) {
            m[ring[i]].push_back(i);
        }
        
        // dp[i][j] = number of moves to achieve characters
        // from position j to key.size - 1, with ring[i] be
        // the current 12:00 character.
        vector<vector<int>> dp(ring.size(), vector<int>(key.size(), 1e9));
        
        for (int ind = key.size() - 1; ind >= 0; --ind) {
            for (int mark = 0; mark < ring.size(); ++mark) {
                
                // We want to achieve character key[ind],
                // so we try all appearances of key[ind] in ring
                for (int pos : m[key[ind]]) {
                    
                    // Calculate the clockwise and counterclockwise
                    // to turn from current <mark> to <pos>.
                    int turn = abs(mark - pos);
                    turn = min(turn, (int)ring.size() - turn);
                    
                    // The number of moves include <turn> to rotate
                    // to correct character on ring, 1 move to press
                    // enter, and plus the number of moves to achieve
                    // key[ind+1:] with cursor at <pos> (= dp[pos][ind+1])
                    dp[mark][ind] = min(dp[mark][ind], 1 + turn + (ind+1 < key.size() ? dp[pos][ind+1] : 0));
                }
            }
        }
        return dp[0][0];
    }
};
