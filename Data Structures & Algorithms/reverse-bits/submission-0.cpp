class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int result = 0;
        for (int i = 0; i < 32; i++) {
            int bit = n & 1;
            result = (result << 1) | bit;
            n >>= 1;
        }
        return result;
    }
};

/**
 * Reverses the binary representation of a 32-bit unsigned integer.
 * Extracts the rightmost bit using bitwise AND, then shifts the result
 * left and appends the extracted bit using bitwise OR.
 * Right-shifts the input after each iteration to process the next bit.
 * Performs exactly 32 iterations to account for leading zeroes.
 * Time Complexity: O(1), Space Complexity: O(1).
 */