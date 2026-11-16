class Solution {
public:
    int getSum(int a, int b) {

        while (b != 0) {
            int sum = a ^ b;
            int carry = (a & b) << 1;

            a = sum;
            b = carry;
        }

        return a;
    }
};

/**
 * Adds two integers without using the '+' or '-' operators.
 * Uses XOR to calculate the partial sum without carrying and AND
 * to identify carry bits, which are shifted left by one position.
 * Repeats the process until no carry remains, then returns the sum.
 * Time Complexity: O(1) for fixed-width integers.
 * Space Complexity: O(1).
 */