class Solution {
public:
    int climbStairs(int n) {

        // for this problem we only ever need the previous 2 values        
        int prev2 = 1;
        int prev1 = 1;

        for (int i = 2; i <= n; i++) {
            int curr = prev1 + prev2;

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
