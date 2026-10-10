
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int total = 0;

        for (int x : nums) {
            total += x;
        }

        if (total % 2 != 0) {
            return false;
        }

        
        int target = total / 2;
        vector<bool> dp(target + 1, false);
        
        // a sum of zero is possible
        dp[0] = true;

        for (int x : nums) {
            for (int s = target; s >= x; s--) {
                // Either s was already possible,
                // or we form s by adding x to sum s-x
                dp[s] = dp[s] || dp[s - x];
            }
        }

        return dp[target];
    }
};