class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // take the transpose of the array
        for(int i = 0; i < matrix.size(); i++){ // 0 | 1 | 2
            for(int j = i; j < matrix.size(); j++){ // 0,0, 0,1 0,2 | 1,1 , 1,2 | 2,2 
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        // reverse each row
        for(int i = 0; i < matrix.size(); i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};