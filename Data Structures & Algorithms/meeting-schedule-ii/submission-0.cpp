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
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
            return a.start < b.start;
        });

        // keep track of the ending time of meeting currently happening, using min heap we have earliest ending time with us
        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto& interval : intervals) {
            if(!pq.empty() && pq.top() <= interval.start) {
                pq.pop();
            }

            pq.push(interval.end);
        }

        return pq.size();
    }
};