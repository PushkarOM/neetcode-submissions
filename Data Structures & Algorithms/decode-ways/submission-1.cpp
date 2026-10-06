class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        vector<int> dp(n + 1, 0);

        dp[n] = 1;

        for (int i = n - 1; i >= 0; i--) {

            // Take s[i] as a single digit
            if (s[i] != '0') {
                dp[i] += dp[i+1];
            }

            // Take s[i] and s[i+1] together
            if (i + 1 < n) {
                int num = (s[i] - '0') * 10 + (s[i + 1] - '0');

                if (10 <= num && num <= 26) {
                    dp[i] += dp[i + 2];
                }
            }
        }

        return dp[0];
    }
};

/*
Decode Ways - 1D DP

```
DP STATE:
    dp[i] = number of valid ways to decode the substring
            s[i...n-1].

    In other words:
        "If I start decoding from index i, how many
         complete valid decodings are possible?"


MAIN IDEA:
    At index i, we have at most two choices:

    1. Take s[i] as a single digit.
    2. Take s[i] and s[i+1] together as a two-digit number.

    We only make a choice if the resulting number is valid.


CHOICE 1: TAKE ONE DIGIT

    A single digit is valid only when it is 1-9.

        s[i] != '0'

    If valid, we move one position forward:

        dp[i] += dp[i+1]


    IMPORTANT:
        0 cannot be decoded by itself.

        "0"  -> invalid
        "01" -> invalid

        But 0 can be part of a valid two-digit number:

        "10" -> J
        "20" -> T


CHOICE 2: TAKE TWO DIGITS

    Two digits form a valid letter only when their value
    is between 10 and 26.

        10 <= number(s[i], s[i+1]) <= 26

    If valid, we consume both digits and move two positions:

        dp[i] += dp[i+2]


RECURRENCE:

    dp[i] = 0

    if s[i] != '0':
        dp[i] += dp[i+1]

    if i+1 exists and 10 <= s[i...i+1] <= 26:
        dp[i] += dp[i+2]


WHY DO WE CALCULATE FROM RIGHT TO LEFT?

    The state dp[i] depends on:

        dp[i+1]
        dp[i+2]

    Therefore these states must already be calculated
    before calculating dp[i].

    So we process:

        i = n-1, n-2, ..., 0

    IMPORTANT:

        We are NOT decoding the string backwards.

        The actual decoding is still conceptually
        left to right.

        We are only calculating the DP answers
        right to left because of their dependencies.


BASE CASE:

    dp[n] = 1

    Reaching the end of the string means we have
    successfully decoded everything.

    There is exactly one way to finish:
        do nothing.

    This "1" allows the final valid choice to
    contribute to the answer.


EXAMPLE: "12"

    At index 0 we have two valid choices:

        1 | 2
        12

    Therefore:

        dp[0] = dp[1] + dp[2]

    giving:

        "AB"
        "L"

    Answer = 2.


EXAMPLE: "10"

    At index 0:

        1 | 0    -> invalid because 0 cannot stand alone
        10       -> valid

    Therefore only "10" contributes.

    Answer = 1.


MENTAL MODEL:

    Think of every index as a position from which
    we can make jumps:

            i
           / \
          /   \
       i+1    i+2
      1 digit  2 digits

    Each valid jump represents a decoding choice.

    dp[i] counts all valid paths from index i
    until the end.


COMPLEXITY:

    Time:  O(n)
        Each index is processed once and each index
        checks at most two choices.

    Space: O(n)
        We store one DP value for each index.
```

*/
