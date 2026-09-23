class Solution {
public:
    struct Compare {
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) {
            if (a.second != b.second)
                return a.second > b.second;

            return a.first > b.first;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            Compare
        > pq;

        for(int i = 0; i < points.size(); i++){
            
            int temp1 =  points[i][0] * points[i][0];
            int temp2 =  points[i][1] * points[i][1];            
            int dist = temp1 + temp2;
            pq.push({i,dist});

        }

        vector<vector<int>> result;
        for(int i = 0; i < k; i++){
            pair<int,int> temp = pq.top();
            pq.pop();

            result.push_back(points[temp.first]);
        
        }

        return result;
    }
};
