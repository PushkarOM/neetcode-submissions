class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        // here dp i, mean longest subsequence ending at that index
        vector<int> dp(n,1);

        int ans = 1;
        
        // at every i index we check all previous if any has a element smaller than element at i, if yes, we then check appeding our current i element to it would increase the length of subsequence or not, and update the dp accrodingly.
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]) dp[i] = max(dp[i],dp[j]+1);
            }
            
            ans = max(ans, dp[i]);
        }        

        return ans;
    }
};
