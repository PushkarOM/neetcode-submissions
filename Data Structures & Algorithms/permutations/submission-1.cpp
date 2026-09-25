class Solution {
public:
    void backtrack(vector<vector<int>>& result, vector<int> curr, vector<int>& used, vector<int>& nums){

        if(curr.size() == nums.size()){
            result.push_back(curr);
            return;
        }

        for(int i = 0; i <  nums.size(); i++){
            if(used[i] == 1) continue;

            used[i] = 1;
            curr.push_back(nums[i]);

            backtrack(result, curr, used, nums);

            curr.pop_back();
            used[i] = 0;
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> used(nums.size(),0);
        vector<int> curr;

        backtrack(result, curr, used, nums);

        return result;
    }
};

// Pattern 3: Permutations
//
// backtrack():
//     if curr.size() == n:
//         save curr
//         return
//
//     for i = 0 → n-1:
//         if used[i]:
//             continue
//
//         choose nums[i]
//         used[i] = true
//
//         backtrack()
//
//         undo:
//         used[i] = false
//         remove nums[i]
