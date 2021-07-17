class Solution {
public:
    string smallestSubsequence(string s) {
        // Find the last occurence of each character.
        unordered_map<char, int> lastOccurence;
        for (int i = 0; i < s.size(); ++i) {
            lastOccurence[s[i]] = i;
        }
        stack<char> result;
        unordered_map<char, bool> appeared;
        for (int i = 0; i < s.size(); ++i) {
            // If this character already appears, we don't need
            // to add it to the result anymore.
            if (appeared[s[i]] == true)
                continue;
            // Try to push out the larger characters than s[i]
            // as long as we make sure these characters will
            // appear again later.
            while (result.empty() == false && lastOccurence[result.top()] > i && result.top() > s[i]) {
                appeared[result.top()] = false;
                result.pop();
            }
            // Push s[i] into the result.
            appeared[s[i]] = true;
            result.push(s[i]);
        }
        string answer = "";
        while (result.empty() == false) {
            answer += result.top();
            result.pop();
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
