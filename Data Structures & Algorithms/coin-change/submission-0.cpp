class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp represent the min number of coins to make amount i
        vector<int> dp(amount + 1, amount + 1);

        dp[0] = 0; // for amount 0, we don't need any coin

        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin <= i) {
                    // for every amount i, check which is minmum, amount i itself, or (i - coin) + 1, i.e keeping 1 coin of "coin" amount and rest of i-coin amount
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        // if in the end the dp[amount] is > amount + 1 , i.e and impossible vlaue in context of the question then we didn't find such a combination.
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

/**
 * Coin Change - 1D Dynamic Programming
 *
 * Idea:
 *   dp[i] = minimum number of coins needed to make exactly amount i.
 *
 * Base case:
 *   dp[0] = 0
 *   Making amount 0 requires 0 coins.
 *
 * Transition:
 *   For every amount i, try using each coin as the LAST coin.
 *
 *   If coin <= i:
 *       dp[i] = min(dp[i], dp[i - coin] + 1)
 *
 *   Why?
 *   If coin is the last coin used, then we first need to make
 *   (i - coin), which takes dp[i - coin] coins, and then add
 *   this one coin.
 *
 * Initialization:
 *   Start every dp[i] with amount + 1, representing "impossible".
 *   amount + 1 is larger than any possible valid answer.
 *
 * Example:
 *   coins = [1, 5, 10], amount = 12
 *
 *   dp[12] considers:
 *       coin 1  -> dp[11] + 1
 *       coin 5  -> dp[7]  + 1
 *       coin 10 -> dp[2]  + 1 = 3
 *
 *   Therefore dp[12] = 3 (10 + 1 + 1).
 *
 * Final:
 *   If dp[amount] is still amount + 1, the amount is impossible,
 *   so return -1. Otherwise return dp[amount].
 *
 * Complexity:
 *   Time:  O(amount * coins.size())
 *   Space: O(amount)
 */