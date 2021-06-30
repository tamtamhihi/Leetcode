class Solution {
public:

    // The main idea here is that the concatenation contains no intervention,
    // so we try to divide string s into consecutive k-sized words (k = words[i].size)
    // and use 2 pointers technique to find windows that contain all given words.

    vector<int> findSubstring(string s, vector<string>& words) {
        int k = words[0].size();
        int n = s.size();
        
        // s is shorter than a word itself, 
        // so it cannot contain any concatenation.
        if (n < k)
            return vector<int>();
        
        // Count number of distinct strings and
        // appearances of each string in words.
        // This will be used to find the windows.
        unordered_map<string, int> wordsCount;
        int totalCount = 0;
        for (int i = 0; i < words.size(); ++i) {
            wordsCount[words[i]] += 1;
            if (wordsCount[words[i]] == 1)
                ++totalCount;
        }

        // To avoid duplicate answers, we used a hashed set here.
        vector<int> answer;
        unordered_set<int> ans;
  
        
        
        // Here's the main part: We try to split string s
        // into consecutive k-sized words.
        // Note that the partitions will be different
        // depending on the positions that we start.

        // For example: s = "hifoobar", k = 3, words = ["foo", "bar"]
        // We can partition s into:

        //    ["hif", "oob"] starting at position = 0 of s
        // or ["ifo", "oba"] at position = 1
        // or ["foo", "bar"] at position = 2 (this makes sense and produces an answer)

        // Note that if we start at position = 3, it's the same as starting at 0
        // (and we miss out the first "hif"). So the start is from 0 to k - 1.

        for (int start = 0; start <= k - 1; ++start) {
            
            int noGroup = (n - start) / k;
            vector<string> groups(noGroup);

            // The i-th k-sized word is from
            // s[start + i * k] to s[start + i * k + k - 1]

            for (int i = 0; i < noGroup; ++i) {
                string word = "";
                for (int index = 0; index < k; ++index)
                    word += s[start + i * k + index];

                // We only keep the k-sized word that appears in <words>
                if (wordsCount.find(word) != wordsCount.end()) {
                    groups[i] = word;
                }
                else {
                    groups[i] = "";
                }
            }
            

            // After constructing the partitioned words,
            // we use two pointers to find a window in <groups>
            // that contains all in <words> without intervention.

            unordered_map<string, int> count;
            int cnt = 0;
            int l = 0;

            for (int r = 0; r < noGroup; ++r) {
                if (groups[r] == "") {
                    l = r + 1;
                    cnt = 0;
                    count.clear();
                    continue;
                }

                count[groups[r]] += 1;
                if (count[groups[r]] == wordsCount[groups[r]])
                    ++cnt;

                // groups[r] appears more times than needed in 
                // current window [l, r] --> increase l until sufficient
                while (count[groups[r]] > wordsCount[groups[r]]) {
                    if (count[groups[l]] == wordsCount[groups[l]])
                        --cnt;
                    count[groups[l]] -= 1;
                    ++l;
                }
                
                if (cnt == totalCount) {
                    // The l-th group is the beginning of this window.
                    int beginInd = start + k * l;
                    if (!ans.count(beginInd)) {
                        ans.insert(beginInd);
                        answer.push_back(beginInd);
                    }
                }
            }
        }
        return answer;
    }
};