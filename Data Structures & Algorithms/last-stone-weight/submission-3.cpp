class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> pq(stones.begin(), stones.end());

        int x, y;

        while(pq.size() > 1){
            y = pq.top();
            pq.pop();

            x = pq.top();
            pq.pop();

            if(x < y){
                pq.push(y - x);
            }
        }

        return pq.empty() ? 0 : pq.top();
    }
};