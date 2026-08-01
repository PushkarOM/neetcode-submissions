class Solution {
public:
    int search(vector<int>& nums, int target) {
        

        // 2 things to check, find the sorted half
        // inside that check , if target lies in it, if yes go in, else go to the other half

        int low = 0, high = nums.size()-1, mid;

        while(low <= high){
            mid = low + (high - low)/2;

            if(nums[mid] == target){
                return mid;
            }

            // left half is sorted
            if(nums[low] <= nums[mid]){

                if(nums[low] <= target && nums[mid] > target){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            // right half automatically sorted
            else{
                if(target > nums[mid] && target <= nums[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};
