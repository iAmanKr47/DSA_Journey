//using bfs as it would cover all rotten eggs at once 

class Solution {
public:
    int maxTime = 0;
    void bfs(vector<vector<int>>& grid, queue<vector<int>>& q) {
        // insert all rotten oranges that are present initially
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j, 0});
                }
            }
        }
        /// bfs traversal
        while (q.size() > 0) {
            auto front = q.front();
            q.pop();
            int i = front[0];
            int j = front[1];
            auto time = front[2];
            maxTime = max(maxTime, time );
            if (i - 1 >= 0 && i - 1 < grid.size() && j >= 0 &&
                j < grid[0].size() && grid[i - 1][j] == 1) {
                q.push({i - 1, j, time + 1});
                grid[i-1][j] = 2;
            }

            if (i + 1 >= 0 && i + 1 < grid.size() && j >= 0 &&
                j < grid[0].size() && grid[i + 1][j] == 1) {
                q.push({i + 1, j, time + 1});
                 grid[i+1][j] = 2;
            }

            if (i >= 0 && i < grid.size() && j - 1 >= 0 &&
                j - 1 < grid[0].size() && grid[i][j - 1] == 1) {
                grid[i][j - 1] = 2;
                q.push({i, j - 1, time + 1});
                
            }

            if (i >= 0 && i < grid.size() && j + 1 >= 0 &&
                j + 1 < grid[0].size() && grid[i][j + 1] == 1) {
                grid[i][j + 1] = 2;
                q.push({i, j + 1, time + 1});
                
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        //vector<vector<int>> vis = grid;
        queue<vector<int>> q; // row,col,time
        bfs(grid, q);
        // check if still any fresh oranges are left then return -1
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }
        return maxTime;
    }
};
