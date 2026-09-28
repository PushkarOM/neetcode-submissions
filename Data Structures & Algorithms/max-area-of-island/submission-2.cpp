class Solution {
public:
    void dfs(vector<vector<int>>& grid, int r, int c, int& area) {

        // Outside grid or already visited/water
        if (r < 0 || c < 0 ||
            r >= grid.size() ||
            c >= grid[0].size() ||
            grid[r][c] == 0) {
            return;
        }

        // Mark as visited
        grid[r][c] = 0;
        area++;

        // Explore all 4 neighbors
        dfs(grid, r + 1, c, area); // down
        dfs(grid, r - 1, c, area); // up
        dfs(grid, r, c + 1, area); // right
        dfs(grid, r, c - 1, area); // left
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0, area = 0;

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {

                if (grid[r][c] == 1) {
                    // Explore and mark the entire island
                    area = 0; // reset the area
                    dfs(grid, r, c, area);

                    maxArea = max(maxArea,area);
                }
            }
        }

        return maxArea;
    }
};
