class Solution {
public:

    int robRange(vector<int>& nums, int left, int right) {

        int prev2 = nums[left];
        int prev1 = max(nums[left], nums[left + 1]);

        for(int i = left + 2; i <= right; i++) {

            int curr = max(
                nums[i] + prev2,
                prev1
            );

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
}

    int rob(vector<int>& nums) {
        int n = nums.size();

        
        if(n == 1)
            return nums[0];

        if(n == 2)
            return max(nums[0], nums[1]);
        
        return max(
            robRange(nums, 0, n-2),
            robRange(nums, 1, n-1)
        );
    }
};
