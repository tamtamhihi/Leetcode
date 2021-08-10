class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int zero = 0, one = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '0') {
                one = min(one, zero) + 1;
            } else {
                one = min(one, zero);
                ++zero;
            }
        }
        return min(zero, one);
    }
};
