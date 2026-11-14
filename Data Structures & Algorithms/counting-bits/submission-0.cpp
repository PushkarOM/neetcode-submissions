class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> output(n + 1, 0);

        for (int i = 0; i <= n; i++) {
            int curr = i;

            while (curr) {
                curr &= (curr - 1);
                output[i]++;
            }
        }

        return output;
    }
};
