class Solution {
public:
    string minWindow(string s, string t) {

        if (t.length() > s.length())
            return "";

        vector<int> freqT(128, 0);
        vector<int> window(128, 0);

        for (char c : t)
            freqT[c]++;

        int required = t.length();   // characters still needed

        int left = 0;
        int start = 0;
        int minLen = INT_MAX;

        for (int right = 0; right < s.length(); right++) {

            window[s[right]]++;

            // If this character was needed, we've satisfied one more requirement.
            if (freqT[s[right]] > 0 && window[s[right]] <= freqT[s[right]])
                required--;

            // While the current window contains all required characters
            while (required == 0) {

                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Remove the leftmost character
                window[s[left]]--;

                // If removing it makes us lose a required character,
                // the window is no longer valid.
                if (freqT[s[left]] > 0 && window[s[left]] < freqT[s[left]])
                    required++;

                left++;
            }
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};