class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char,int> w;
        int len = 0;

        int i = 0, j = 0; // start and end of window
        while(i < s.length() && j < s.length()){
            w[s[j]]++;

            while(w[s[j]] >= 2){
                w[s[i]]--;
                i++;
            }
            len = max(len, j-i+1);
            j++;
        }

        return len;
    }
};
