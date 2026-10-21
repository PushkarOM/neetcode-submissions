
class Solution {
public:
    int jump(vector<int>& nums) {

        if(nums.size() == 1) return 0;

        int count_ = 0;
        int i = 0;

        while(i < nums.size() - 1){

            int l = i + 1;
            int r = min(i + nums[i], (int)nums.size() - 1);

            int maxReach = -1;
            int bestIndex = i;

            if(r == nums.size() - 1){
                return count_ + 1;
            }

            while(l <= r){
                if(l + nums[l] > maxReach){
                    maxReach = l + nums[l];
                    bestIndex = l;
                }
                l++;
            }

            i = bestIndex;
            count_++;
        }

        return count_;
    }
};
