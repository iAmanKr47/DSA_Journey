int islandPerimeter(vector<vector<int>>& grid) {
        int boundary=0;
        int row=grid.size();
        int col=grid[0].size();
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    boundary += 4;
                    if (i > 0 && grid[i - 1][j] == 1)
                        boundary--;
                    if (i < row - 1 && grid[i + 1][j] == 1)
                        boundary--;
                    if (j > 0 && grid[i][j - 1] == 1)
                        boundary--;
                    if (j < col - 1 && grid[i][j + 1] == 1)
                        boundary--;
                }
            }
        }
       return boundary;
    }
