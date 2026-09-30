class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        
        // nunmber of rows and column
        int rows = grid.size();
        int cols = grid[0].size();

        // Queue stores cell from which BFS will spead/start
        // here bfs will start from each treasure spreading outwards defining distance of each cell
        queue<pair<int,int>> q;

        // Put all the treasure cells into the queue
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                
                if(grid[r][c] == 0) q.push({r,c});

            }
        }

        // 4 possible direction from a cell
        int directions[4][2] ={
            {1,0},
            {-1,0},
            {0,1},
            {0,-1}
        };

        while(!q.empty()){

            // Take the next cells until there is nothing left
            // at start this will be locs of treasures
            auto [r,c] = q.front();
            q.pop();

            
            // checking/Updating in each directions
            for(auto& dir : directions){
                
                int nr = r + dir[0];
                int nc = c + dir[1];

                // Ignore cells outside the grid
                if(nr < 0 || nr >= rows ||
                   nc < 0 || nc >= cols) continue;

                // if we hit a wall/water
                if(grid[nr][nc] == -1) continue;

                // if cell already has a distance
                if(grid[nr][nc] != INT_MAX) continue;

                // Distance = current cell's distance + 1
                grid[nr][nc] = grid[r][c] + 1;

                // Add this new cell to the queue to be further explored
                q.push({nr,nc});
            }
        }
    }
};
