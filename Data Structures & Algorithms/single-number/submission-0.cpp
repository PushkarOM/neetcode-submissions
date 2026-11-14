class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // XOR of same digit produce 0
        // XOR with zero produces same digit back

        int xorResult = 0;
        for(auto it : nums){
            xorResult ^= it;
        }

        return xorResult;
    }
};
