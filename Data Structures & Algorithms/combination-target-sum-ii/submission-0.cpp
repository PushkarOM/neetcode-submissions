class Solution {
public:

    void backtrack(vector<vector<int>>& result, vector<int> curr, vector<int>& candidates, int rem, int index){

        if(rem == 0){
            result.push_back(curr);
            return;
        }

        
        for(int j = index; j < candidates.size(); j++){

            if(j > index && candidates[j-1] == candidates[j]) continue;
            if(candidates[j] > rem) break;

            curr.push_back(candidates[j]);

            backtrack(result, curr, candidates, rem - candidates[j], j+1);

            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> result;
        vector<int> curr;
        int rem = target;

        backtrack(result, curr, candidates, rem, 0);
        return result;
    }
};

// Pattern 2: Loop over choices
//
// backtrack(start, remaining):
//     if remaining == 0:
//         save curr
//         return
//
//     for j = start → n-1:
//         if j > start AND nums[j] == nums[j-1]:
//             continue              // skip duplicate at same level
//
//         if nums[j] > remaining:
//             break                 // sorted → rest also too large
//
//         choose nums[j]
//         backtrack(j + 1, remaining - nums[j])
//         undo nums[j]
//
// Key:
//     j + 1 → each index used at most once
//     duplicate check → avoid duplicate combinations
