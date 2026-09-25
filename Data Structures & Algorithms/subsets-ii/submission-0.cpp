class Solution {
public:
    void backtrack(vector<vector<int>>& result, vector<int> curr, vector<int>& nums, int index){

        result.push_back(curr);

        for(int i = index; i < nums.size(); i++){
            if(i > index && nums[i-1] == nums[i]) continue;

            // pick the current element
            curr.push_back(nums[i]);

            backtrack(result, curr, nums, i+1);

            curr.pop_back();
        }

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> curr;
        backtrack(result, curr, nums, 0);

        return result;
    }
};

// Pattern 1: Pick/Don't Pick → save only when i == n,
// because we must decide for every element.

// Pattern 2: Loop over choices → save curr at every call,
// because every curr is already a valid answer.
