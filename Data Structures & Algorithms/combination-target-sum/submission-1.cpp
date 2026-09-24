class Solution {
public:
    
    void backtrack(vector<vector<int>>& result, vector<int>& curr, int sum, int target, vector<int>& nums, int i){
        
        if(sum > target) return;
        
        if(sum == target){
            result.push_back(curr);
            return;
        }

        if (i == nums.size()) return;

        // pick the current element

        curr.push_back(nums[i]);
        sum += nums[i];
        backtrack(result, curr, sum, target, nums, i);
        sum -= nums[i];
        curr.pop_back();

        
        backtrack(result, curr, sum, target, nums, i+1);

    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        int sum = 0;

        backtrack(result, curr, sum, target, nums, 0);
        return result;
    }
};

// Pattern 1: Pick / Don't Pick
//
// PICK:
//     add nums[i]
//     recurse with i          ← stay → can pick same element again
//     undo
//
// DON'T PICK:
//     recurse with i + 1      ← move to next element
