class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // deafult way is to push the new interval in, sort the inverval via start index of interval, then merge
        intervals.push_back(newInterval);

        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
            return a[0] < b[0];
        });  

        // merge intervals
        int start = intervals[0][0];
        int end = intervals[0][1];
        
        vector<vector<int>> result;

        for(int i = 1; i < intervals.size(); i++){
            
            if(intervals[i][0] <= end){
                end = max(intervals[i][1], end);
            }
            else{
                result.push_back({start, end});
                
                start = intervals[i][0];
                end = intervals[i][1];
            }

        }   

        // last interval left
        result.push_back({start, end});
        
        return result;    
    }
};
