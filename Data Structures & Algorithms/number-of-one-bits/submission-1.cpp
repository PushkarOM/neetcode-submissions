class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;

        while (n) {
            count++;
            n &= (n - 1);
        }

        return count;
    }
};

// right shift approach
// Check the rightmost bit using n & 1, then right-shift n.
// Repeat until all bits have been processed.

// Brian Kernighan's Algorithm
// n & (n - 1) removes the rightmost set bit (1).
// Count how many times this operation can be performed until n becomes 0.
