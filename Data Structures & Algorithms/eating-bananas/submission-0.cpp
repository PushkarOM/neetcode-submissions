class Solution {
public:

    bool checkValidK(vector<int>& arr, int k, int h){
        int hour = 0;
        for(int i = 0; i < arr.size(); i++){
            hour += arr[i] <= k ? 1 : ceil((double)arr[i] / k);
        }

        return hour <= h ? true : false;
    }


    int minEatingSpeed(vector<int>& piles, int h) {
        
       // max limit is max(piles) for k
       // min limit is min(piles) for k
       // Allowed min value (the least bount as per given problem contraint) = eat bannas in h hours
       // find the max of original array, create a array 1 to max, apply binary search
       // if the setting current pile as k is allowed, try going low, 
       // else high, till low high converge

        int maxVal = *max_element(piles.begin(), piles.end());

        int low = 1, high = maxVal;
        int ans = 0;

        while(low <= high){

            int mid = low + (high - low) / 2;

            if(checkValidK(piles, mid, h)){
                // try going lower
                ans = mid;
                high = mid - 1;
            }
            else{
                // try going higher
                low = mid + 1;
            }

        }

        return ans;

    }
};
