class Solution {
public:
    vector<int> countBits(int n) {

        vector<int> output(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            output[i] = output[i >> 1] + (i & 1);
        }

        return output;
    }
};


/**
 * Uses DP to count set bits for every number from 0 to n.
 * Removes the last bit using right shift and adds it if it is 1.
 * Reuses previously computed results to achieve O(n) time.
 */

