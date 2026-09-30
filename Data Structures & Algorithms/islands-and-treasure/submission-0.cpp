class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q;

        // Put ALL treasures into the queue
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {

                if(grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        int directions[4][2] = {
            {1, 0},   // down
            {-1, 0},  // up
            {0, 1},   // right
            {0, -1}   // left
        };

        while(!q.empty()) {

            auto [row, col] = q.front();
            q.pop();

            for(auto& dir : directions) {

                int nr = row + dir[0];
                int nc = col + dir[1];

                // Outside grid
                if(nr < 0 || nr >= rows ||
                   nc < 0 || nc >= cols) {
                    continue;
                }

                // Wall
                if(grid[nr][nc] == -1) {
                    continue;
                }

                // Already processed / has a shorter distance
                if(grid[nr][nc] != INT_MAX) {
                    continue;
                }

                // Current cell's distance + 1
                grid[nr][nc] = grid[row][col] + 1;

                q.push({nr, nc});
            }
        }
    }
};