class Solution {
public:
    // BFS starting from a set of ocean-border cells
    void bfs(
        vector<vector<int>>& heights,
        vector<vector<bool>>& visited,
        queue<pair<int,int>>& q
    ){

        // Numbers of rows and columns
        int rows = heights.size();
        int cols = heights[0].size();

        int directions[4][2] = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}            
        };

        while(!q.empty()){

            auto [r,c] = q.front();
            q.pop();

            for(auto& dir : directions){
               
                int nr = r + dir[0];
                int nc = c + dir[1];

                if(nr < 0 || nr >= rows ||
                   nc < 0 || nc >= cols){
                    continue;
                }
                // check if visited
                if(visited[nr][nc] == true) continue;
                
                // Height Condition Check
                if(heights[nr][nc] < heights[r][c]) continue;

                // mark visited
                visited[nr][nc] = true;

                // potential visit
                q.push({nr,nc});
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> pacific(
            rows, vector<bool>(cols, false)
        );

        vector<vector<bool>> atlantic(
            rows, vector<bool>(cols, false)
        );

        queue<pair<int,int>> pacificQueue;
        queue<pair<int,int>> atlanticQueue;

        // PACIFIC SOURCES

        // Top row
        for(int c = 0; c < cols; c++) {
            
            pacificQueue.push({0,c});
            
            pacific[0][c] = true;
        
        }

        // Left column
        for(int r = 0; r < rows; r++) {

            pacificQueue.push({r,0});

            pacific[r][0] = true;
        }


        // =========================
        // ATLANTIC SOURCES
        // =========================

        // Bottom row
        for(int c = 0; c < cols; c++) {

            atlanticQueue.push({rows-1,c});
            
            atlantic[rows-1][c] = true;
        }

        // Right column
        for(int r = 0; r < rows; r++) {
            
            atlanticQueue.push({r,cols-1});

            atlantic[r][cols-1] = true;
        }


        // Run BFS from Pacific
        bfs(heights, pacific, pacificQueue);

        // Run BFS from Atlantic
        bfs(heights, atlantic, atlanticQueue);


        // FIND CELLS REACHABLE
        // FROM BOTH OCEANS

        vector<vector<int>> result;

        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {

                if(pacific[r][c] && atlantic[r][c]) result.push_back({r,c});
            }
        }

        return result;
    }
};
