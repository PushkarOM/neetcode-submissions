class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;
        for(int i = 0; i < gas.size(); i++){
            totalGas += gas[i];
            totalCost += cost[i];
        }

        if(totalGas < totalCost)
            return -1;

        int total = 0;
        int index = 0;

        for(int i = 0; i < gas.size(); i++){
            total += gas[i] - cost[i];
            if(total < 0){
                total = 0;
                index = i + 1;
            }
        }

        return index % gas.size();
    }
};
