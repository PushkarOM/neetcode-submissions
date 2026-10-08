class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        unordered_set<string> words(wordDict.begin(), wordDict.end());

        // mark the ending position of a valid word as true
        vector<bool> dp(n + 1, false);

        dp[0] = true; // nothing before the starting position

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {

                // j is a valid position
                // check if the part from j to i is a word in the dictionary
                if (dp[j] && words.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};