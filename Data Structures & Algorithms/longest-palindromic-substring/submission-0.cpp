class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();

        vector<vector<bool>> dp(n, vector<bool>(n,false));

        int start = 0;
        int maxLen = 1;

        // for a string i,j to be palindrom i+1,j-1 (i.e string inside it should be a palindrom)
        for(int i = n-1; i >= 0; i--){
            for(int j = i; j < n; j++){
                
                if((s[i] == s[j]) && (j-i <= 2 || dp[i+1][j-1])){
                    dp[i][j] = true;
                    int len = j-i+1;
                    if(len > maxLen){
                        maxLen = len;
                        start = i;
                    }
                }
            }
        }   

        return s.substr(start, maxLen);
    }
};
