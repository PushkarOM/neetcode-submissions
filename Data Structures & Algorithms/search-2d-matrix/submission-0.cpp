class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // applying binary search to 2D Array
        int n = matrix.size();

        int m = matrix[0].size();

        int low = 0, high = n * m - 1;

        // Perform binary search
        while (low <= high) {
            int mid = (low + high) / 2;

            // Convert mid index to corresponding 2D indices
            int row = mid / m;
            int col = mid % m;

            if (matrix[row][col] == target)
                return true;

            else if (matrix[row][col] < target)
                low = mid + 1;

            else
                high = mid - 1;
        }
        return false;
    }
};