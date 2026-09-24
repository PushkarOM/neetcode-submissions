class Solution {
public:
    void backtrack(vector<vector<int>>& result, vector<int> curr, vector<int>& nums, int i){


        if(i == nums.size()) {
            result.push_back(curr);
            return;
        }

        // pick the current element
        curr.push_back(nums[i]);

        backtrack(result, curr, nums, i+1);

        curr.pop_back();

        // don't pick current element
        backtrack(result, curr, nums, i+1);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        backtrack(result, curr, nums, 0);

        return result;
    }
};

// Pattern 1: Pick / Don't Pick
// At each index, make 2 choices:
//     1. Pick nums[i]  → add to curr → recurse → undo
//     2. Don't pick     → recurse without adding
//
// Pseudo:
// backtrack(i):
//     if i == n:
//         save curr
//         return
//
//     curr.push(nums[i])     // PICK
//     backtrack(i + 1)
//     curr.pop()             // UNDO
//
//     backtrack(i + 1)       // DON'T PICK
