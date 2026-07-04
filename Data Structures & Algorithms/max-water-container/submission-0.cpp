class Solution {
public:
    int maxArea(vector<int>& height) {
        
        // 2 pointers
        int first = 0, last = height.size() - 1;
        long long int maxVol = INT_MIN, currVol;
        
        while(first < last){

            if(height[first] - height[last] < 0){
                
                currVol = height[first] * abs(last-first);
                if(currVol > maxVol) maxVol = currVol;
                first++;
            }
            else{
                currVol = height[last] * abs(last-first);
                if(currVol > maxVol) maxVol = currVol;
                last--;
            }

        }
        return maxVol;
    
    }
};