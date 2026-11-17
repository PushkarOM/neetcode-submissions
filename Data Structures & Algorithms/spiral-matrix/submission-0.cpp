class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // set 4 boundaries
        int top  = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;
        
        vector<int> ans;

        while(top <= bottom && left <= right){

            // left to right
            for(int i = left; i <= right; i++){ 
                ans.push_back(matrix[top][i]); 
            }
            top++; // it now point to the next row

            // top to bottom
            for(int i  = top; i <= bottom; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;

            // right to left
            if(top <= bottom){
                for(int i = right; i >= left; i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // bottom to top
            if(left <= right){
                for(int i = bottom; i >= top; i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return ans;

    }
};


/*
 * SPIRAL MATRIX - FOUR POINTER APPROACH
 *
 * Maintain four pointers to define the boundaries of the
 * unvisited portion of the matrix.
 *
 *       left                 right
 *         |                    |
 *         v                    v
 *    +------+------+------+------+
 *    |  1   |  2   |  3   |  4   |  <-- top
 *    +------+------+------+------+
 *    |  5   |  6   |  7   |  8   |
 *    +------+------+------+------+
 *    |  9   |  10  |  11  |  12  |
 *    +------+------+------+------+
 *    |  13  |  14  |  15  |  16  |  <-- bottom
 *    +------+------+------+------+
 *
 * POINTERS:
 *   top    = First unvisited row
 *   bottom = Last unvisited row
 *   left   = First unvisited column
 *   right  = Last unvisited column
 *
 * TRAVERSAL ORDER:
 *
 *   1. LEFT -> RIGHT
 *      Traverse the top row from left to right.
 *      Update: top++;
 *
 *   2. TOP -> BOTTOM
 *      Traverse the right column from top to bottom.
 *      Update: right--;
 *
 *   3. RIGHT -> LEFT
 *      Traverse the bottom row from right to left.
 *      SAFETY CHECK: if (top <= bottom)
 *      Why? The top traversal may have consumed the
 *      last remaining row. Avoid visiting it again.
 *      Update: bottom--;
 *
 *   4. BOTTOM -> TOP
 *      Traverse the left column from bottom to top.
 *      SAFETY CHECK: if (left <= right)
 *      Why? The right traversal may have consumed the
 *      last remaining column. Avoid visiting it again.
 *      Update: left++;
 *
 * CONDITIONS:
 *
 *   while (top <= bottom && left <= right)
 *      Ensures an unvisited rectangle still exists.
 *
 *   if (top <= bottom)
 *      Ensures a bottom row still exists before
 *      traversing RIGHT -> LEFT.
 *
 *   if (left <= right)
 *      Ensures a left column still exists before
 *      traversing BOTTOM -> TOP.
 *
 * REMEMBER:
 *
 *      Traversal:  ->  ->  ->  ->
 *                  |           |
 *                  ^           v
 *                  |           |
 *      Traversal:  <-  <-  <-  <-
 *
 *      Order:       RIGHT, DOWN, LEFT, UP
 *
 *      Each traversal consumes one boundary.
 *      Shrink that boundary immediately afterward.
 *
 *      Rows are controlled by top and bottom.
 *      Columns are controlled by left and right.
 *
 * TIME COMPLEXITY:  O(m * n)
 * SPACE COMPLEXITY: O(1) auxiliary space
 *                    (excluding the output vector).
 */

