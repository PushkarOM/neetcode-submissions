class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int prev1 = cost[1];
        int prev2 = cost[0];
        int minCost = INT_MAX;

        for(int i = 2; i < cost.size(); i++){
            minCost = cost[i] + min(prev1,prev2);

            prev2 = prev1;
            prev1 = minCost;
        }

        // Top can be reached from either of the last two stairs
        return min(prev1, prev2);
    }
};
