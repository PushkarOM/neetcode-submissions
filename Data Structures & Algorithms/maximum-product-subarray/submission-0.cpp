class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMax = nums[0];
        int currMin = nums[0];

        int answer = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int x = nums[i];

            // Save the old values because both new states
            // must be calculated from the previous states.
            int prevMax = currMax;
            int prevMin = currMin;

            // Three possibilities:
            // 1. Start a new subarray at x
            // 2. Extend the previous maximum
            // 3. Extend the previous minimum
            currMax = max({x, prevMax * x, prevMin * x});
            currMin = min({x, prevMax * x, prevMin * x});

            // Best product seen anywhere so far
            answer = max(answer, currMax);
        }

        return answer;
    }
};