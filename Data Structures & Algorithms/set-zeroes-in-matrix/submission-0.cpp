
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        bool firstRow = false;
        bool firstCol = false;

        // First check whether the entire first row needs to be turned into 0s
        for(int j = 0; j < n; j++){
            if(matrix[0][j] == 0){
                firstRow = true;
                break;
            }
        }

        // Similarly, check whether the entire first column needs to be turned into 0s
        for(int i = 0; i < m; i++){
            if(matrix[i][0] == 0){
                firstCol = true;
                break;
            }
        }

        // Use the first row and first column as markers for the remaining matrix
        // First column (matrix[i][0]) marks whether row i should become 0
        // First row (matrix[0][j]) marks whether column j should become 0
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Process each row except the first one using the first column as marker
        for(int i = 1; i < m; i++){
            if(matrix[i][0] == 0){
                for(int j = 1; j < n; j++){
                    matrix[i][j] = 0;
                }
            }
        }

        // Process each column except the first one using the first row as marker
        for(int j = 1; j < n; j++){
            if(matrix[0][j] == 0){
                for(int i = 1; i < m; i++){
                    matrix[i][j] = 0;
                }
            }
        }

        // Finally, process the first row and first column using their saved flags
        if(firstRow){
            for(int j = 0; j < n; j++){
                matrix[0][j] = 0;
            }
        }

        if(firstCol){
            for(int i = 0; i < m; i++){
                matrix[i][0] = 0;
            }
        }
    }
};
