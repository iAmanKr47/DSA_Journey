//LOGIC USED: same as  find componenets in graph
void dfs(vector<vector<char>>& grid,int i,int j){
        if(i<0||i>=grid.size() || j<0||j>=grid[0].size()|| grid[i][j] == '0')return ;
        grid[i][j]='0';
  // explore all 8 direction
        dfs(grid,i-1,j);
         dfs(grid,i-1,j+1);
          dfs(grid,i-1,j-1);
           dfs(grid,i+1,j);
            dfs(grid,i+1,j+1);
             dfs(grid,i+1,j-1);
              dfs(grid,i,j+1);
               dfs(grid,i,j-1);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    dfs(grid,i,j);
                }
            }
        }
        return cnt;
        
    }
