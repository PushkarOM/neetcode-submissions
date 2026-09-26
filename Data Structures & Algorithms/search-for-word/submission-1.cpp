class Solution {
public:
    bool backtrack(vector<vector<char>>& board, string& word, int row, int col, int index){
        if(index == word.size()){
            return true;
        }

        if(row >= board.size() || col >= board[0].size() || row < 0 || col < 0)     
            return false;

        if(word[index] != board[row][col])
            return false;
        

        board[row][col] = '#'; // this cell is visited

        bool down = backtrack(board, word, row+1, col, index+1);
        bool right = backtrack(board, word, row, col+1, index+1);
        bool up = backtrack(board, word, row-1, col, index+1);
        bool left = backtrack(board, word, row, col-1, index+1); 
        
        board[row][col] = word[index];


        return down || right || up || left;
    
       
    }

    bool exist(vector<vector<char>>& board, string word) {
        
        // call the backtrack for everypotential starting point
        for(int r = 0; r < board.size(); r++){
            for(int c = 0; c < board[0].size(); c++){

                if(backtrack(board, word, r, c, 0))
                    return true;
            }
        }

        return false;
    }
};

// Problem:
// Find whether a given word can be formed in the grid by moving only
// horizontally or vertically. A cell cannot be used more than once.
//
// Approach:
// Try every cell as a possible starting point. Use DFS + backtracking
// to match the word character by character. For each matching cell,
// temporarily mark it as visited, recursively explore all 4 directions,
// and restore the cell afterward so it can be used by another path.
//
// If any path matches the entire word, return true; otherwise false.
// Time: O(R * C * 4^L), Space: O(L), where L = word.length().
