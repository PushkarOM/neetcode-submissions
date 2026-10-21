class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxSum = nums[0];

        for(auto it : nums){
            if(sum < 0){
                sum = 0;
            }
            sum += it;
            maxSum = max(sum,maxSum);
        }
        return maxSum;
    }
};
