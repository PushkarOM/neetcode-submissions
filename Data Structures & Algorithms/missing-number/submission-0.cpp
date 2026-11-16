class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int xorResult = 0;
        for(int i = 0; i <= nums.size(); i++) xorResult ^= i;
        for(auto it : nums) xorResult ^= it;

        return xorResult;
    }
};
