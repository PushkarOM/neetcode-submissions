/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        // sort via the starting of an interval, then check it any interval overlaps
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
            return a.start < b.start;
        }); 

        for(int i = 0; i + 1 < intervals.size(); i++){
            if(intervals[i].end > intervals[i+1].start) return false;
        }

        return true;
    }
};
