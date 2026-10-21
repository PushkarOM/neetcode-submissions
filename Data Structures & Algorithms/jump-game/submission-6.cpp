class Solution {
public:
    bool canJump(vector<int>& nums) {

        if(nums.size() == 1) return true;

        int goal = nums.size() - 1;

        for(int i = goal - 1; i >= 0; i--){
            
            if(i + nums[i] >= goal){
                goal = i;
            }

            if(goal == 0) return true;
        }

        return false;
    }
};
