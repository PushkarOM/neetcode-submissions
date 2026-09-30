class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        // rows and columns
        int rows = grid.size();
        int cols = grid[0].size();

        // storing all the rotten frutis in queue, for Outwards BFS traversal from each of them and storing newly discovered neighbours
        queue<pair<int,int>> q;

        // maintain the fresh fruit count
        int fresh = 0;

        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c] == 2) q.push({r,c});
                if(grid[r][c] == 1) fresh++;
            }
        }


        // the total minutes counts
        int minutes  = 0;

        // Four possible direction of traversal
        int directions[4][2] = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        // loop while there are fresh fruits left, and at least 1 rotten initially
        while(!q.empty() && fresh > 0){

            // number of rotten fruits at  the CURRENT Minute
            int size = q.size();

            // process only this current layer
            for(int i = 0; i < size; i++){

                // Take one rotten fruit
                auto [r,c] = q.front();
                q.pop();

                // check it's four neighbours
                for(auto& dir : directions){

                    int nr = r + dir[0];
                    int nc = c + dir[1];

                    // Ignore cells outside the grid
                    if(nr < 0 || nr >= rows ||
                       nc < 0 || nc >= cols) {
                        continue;
                    }

                     // We only care about fresh fruits
                    if(grid[nr][nc] != 1) {
                        continue;
                    }

                    // Fresh fruit becomes rotten
                    grid[nr][nc] = 2;

                     // One fewer fresh fruit remains
                    fresh--;

                    // This fruit will spread rot
                    // during the NEXT minute
                    q.push({nr, nc});
                }   
            }

            // One complete BFS Layer has passed
            minutes++;
        }

        // If fresh fruits still remain,
        // they could never be reached
        if(fresh > 0) {
            return -1;
        }

        return minutes;
        
    }
};
