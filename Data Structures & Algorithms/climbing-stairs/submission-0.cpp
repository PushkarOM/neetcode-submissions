class Solution {
public:
    int climbStairs(int n) {
        
        // dp array
        vector<int> dp(n+1);

        dp[0] = 1; // being at the start, do nothing 1 move
        dp[1] = 1; // getting to stair 1, 1 move possible

        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};
