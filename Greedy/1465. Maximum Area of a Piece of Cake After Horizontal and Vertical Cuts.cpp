class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int H = 0, W = 0;
        int MOD = 1e9 + 7;
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        for (int i = 1; i < horizontalCuts.size(); ++i) {
            H = max(horizontalCuts[i] - horizontalCuts[i-1], H);
        }
        for (int i = 1; i < verticalCuts.size(); ++i) {
            W = max(verticalCuts[i] - verticalCuts[i-1], W);
        }
        
        return (int)(1LL * H * W % MOD);
    }
};
