class Solution {
public:

    void dfs(vector<vector<char>>& grid, int r, int c) {

        // Outside grid or already visited/water
        if (r < 0 || c < 0 ||
            r >= grid.size() ||
            c >= grid[0].size() ||
            grid[r][c] == '0') {
            return;
        }

        // Mark as visited
        grid[r][c] = '0';

        // Explore all 4 neighbors
        dfs(grid, r + 1, c); // down
        dfs(grid, r - 1, c); // up
        dfs(grid, r, c + 1); // right
        dfs(grid, r, c - 1); // left
    }

    int numIslands(vector<vector<char>>& grid) {

        int islands = 0;

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {

                if (grid[r][c] == '1') {
                    islands++;

                    // Explore and mark the entire island
                    dfs(grid, r, c);
                }
            }
        }

        return islands;
    }
};