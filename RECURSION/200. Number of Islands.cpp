//DFS SOLUTION FOR A 2D MATRIX

void dfs(int i,int j,vector<vector<char>>& grid){
    if(i<0 || i>=grid.size()||j<0 || j>=grid[0].size() || grid[i][j]=='0') return;
    
    grid[i][j]='0';
    dfs(i+1,j,grid);
    dfs(i-1,j,grid);
    dfs(i,j+1,grid);
    dfs(i,j-1,grid);
}
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int islandsCnt=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,grid);
                    islandsCnt++;
                }
            }
        }
        return islandsCnt;
        
    }
