class Solution {
public:

    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int i = k-1;
        int start  = 0;
        
        vector<int> result;

        while(i < nums.size()){

            int it = *max_element(nums.begin()+start, nums.begin()+i+1);
            
            result.push_back(it);
            
            start++;
            i++;
        }
        
        return result;
    }
};
