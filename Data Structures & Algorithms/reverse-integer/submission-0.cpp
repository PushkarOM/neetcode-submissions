
class Solution {
public:
    int reverse(int x) {

        int result = 0;

        while (x != 0) {
            int digit = x % 10;

            // Check for positive overflow
            if (result > INT_MAX / 10 ||
                (result == INT_MAX / 10 && digit > 7))
                return 0;

            // Check for negative overflow
            if (result < INT_MIN / 10 ||
                (result == INT_MIN / 10 && digit < -8))
                return 0;

            result = result * 10 + digit;

            x /= 10;
        }

        return result;
    }
};

/**
 * Checks for integer overflow before appending the next digit.
 * Compares the current result against INT_MAX/10 and INT_MIN/10.
 * If the result reaches either boundary, checks the digit against
 * the respective last digit (7 or -8) to prevent overflow.
 * Returns 0 if the reversed number exceeds the signed 32-bit range.
 */
