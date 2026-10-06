class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();

        vector<vector<bool>> dp(n, vector<bool>(n,false));

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
Count Palindromic Substrings - 2D DP

```
DP STATE:
    dp[i][j] = true if the substring s[i...j] is a palindrome.


MAIN IDEA:
    A substring s[i...j] is a palindrome if:

    1. s[i] == s[j]
    2. The substring inside them, s[i+1...j-1], is also a palindrome.

    Therefore:

    dp[i][j] = s[i] == s[j] &&
               (j - i <= 2 || dp[i+1][j-1])

    For substrings of length <= 3, the inside is either:
    - empty, or
    - a single character, or
    - already trivially palindromic.

    So we don't need to access dp[i+1][j-1] for those cases.


HOW DO WE COUNT THE ANSWER?

    Every true value in dp represents one palindromic substring.

    Therefore, whenever:

        dp[i][j] = true

    we simply increment the count:

        count++;


    Example for "aaa":

         j →  0   1   2
            +---+---+---+
    i = 0  | T | T | T |
    i = 1  |   | T | T |
    i = 2  |   |   | T |
            +---+---+---+

    The 6 true cells represent:

        "a"    "aa"   "aaa"
               "a"    "aa"
                      "a"

    Therefore the answer is 6.


WHY DO WE ITERATE i BACKWARDS?

    dp[i][j] depends on dp[i+1][j-1].

    Example:

        "abba"
         0 1 2 3
         a b b a

    To calculate:

        dp[0][3]

    we need:

        dp[1][2]

    Therefore dp[1][2] must already be calculated.

    We process i from right to left:

        i = n-1, n-2, ..., 0

    This guarantees that the inner substring dp[i+1][j-1]
    has already been computed.


WHY DOES j START FROM i?

    i and j represent the left and right boundaries of a substring.

    A valid substring must satisfy:

        i <= j

    Therefore, for a fixed i:

        j = i, i+1, ..., n-1

    Starting with j = i also handles single-character
    palindromes:

        s[i...i]


IMPORTANT OBSERVATION:

    Unlike Longest Palindromic Substring, we do not need
    to remember the longest palindrome.

    We only need to count every palindrome.

    So:

        dp[i][j] == true
                ↓
            count++


TABLE SHAPE:

    Only the upper triangle represents valid substrings:

         j →
         0   1   2   3
       +---+---+---+---+
    0  | ✓ | ✓ | ✓ | ✓ |
    1  |   | ✓ | ✓ | ✓ |
    2  |   |   | ✓ | ✓ |
    3  |   |   |   | ✓ |
       +---+---+---+---+

    We fill this triangle from bottom to top so that
    dp[i+1][j-1] is available when needed.


COMPLEXITY:
    Time:  O(n^2)
        We check every possible substring.

    Space: O(n^2)
        We store whether every substring is a palindrome.
```

*/



