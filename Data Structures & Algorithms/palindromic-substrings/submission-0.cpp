class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();

        vector<vector<bool>> dp(n, vector<bool>(n,false));

        int start = 0;
        int count = 0;

        // for a string i,j to be palindrom i+1,j-1 (i.e string inside it should be a palindrom)
        for(int i = n-1; i >= 0; i--){
            for(int j = i; j < n; j++){
                
                if((s[i] == s[j]) && (j-i <= 2 || dp[i+1][j-1])){
                    dp[i][j] = true;
                    count++;
                }
            }
        }   

        return count;
    }
};

/*
    Longest Palindromic Substring - 2D DP

    DP STATE:
        dp[i][j] = true if the substring s[i...j] is a palindrome.

    MAIN IDEA:
        A substring is a palindrome if:
        1. Its first and last characters are equal.
        2. Everything inside them is also a palindrome.

        Therefore:

        dp[i][j] = s[i] == s[j] && dp[i+1][j-1]

        For substrings of length <= 3, the inside is either empty
        or a single character, so it is automatically a palindrome.

        Hence:

        dp[i][j] = s[i] == s[j] &&
                   (j - i <= 2 || dp[i+1][j-1])


    WHY DO WE ITERATE i BACKWARDS?

        dp[i][j] depends on dp[i+1][j-1].

        Example:

            "abba"
             i   j
             ↓   ↓
            a b b a

        To calculate dp[0][3], we need dp[1][2].

        Therefore, dp[1][2] must be calculated BEFORE dp[0][3].

        Since the dependency has i+1, we process i from right to left:

            i = n-1, n-2, ..., 1, 0

        This guarantees that dp[i+1][j-1] is already available
        when we need it.


    WHY DOES j START FROM i?

        i and j represent the left and right boundaries of a substring.

        A valid substring must have:

            i <= j

        So when i is fixed, the valid choices for j are:

            j = i, i+1, i+2, ..., n-1

        Starting with j = i also handles the base case of a
        single-character palindrome:

            s[i...i]


    TABLE SHAPE:

        We only need the upper triangle of the DP table because
        states where i > j do not represent normal substrings.

             j →
             0   1   2   3
           +---+---+---+---+
        0  | ✓ | ✓ | ✓ | ✓ |
        1  |   | ✓ | ✓ | ✓ |
        2  |   |   | ✓ | ✓ |
        3  |   |   |   | ✓ |
           +---+---+---+---+

        We fill this triangle from bottom to top so that every
        required inner substring has already been computed.


    COMPLEXITY:
        Time:  O(n^2)  -> we check every possible substring.
        Space: O(n^2)  -> DP table.
*/


