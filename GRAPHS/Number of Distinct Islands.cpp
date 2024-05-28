/*
                                                             Intuition
Idea is to find a way to eliminate silimar island first. For each island, mark the first cell of the island with the coordinate (0,0) 
and the rest of the cells with respect to (0,0), then put all the modified island coordinates into a vector. 
Now the number of distinct vectors is our answer.

                                                           Implementation
Step 1: Take a Set of Vector (to count the number of distinct vectors)
Step 2: Run loop and for each unvisited cell call a dfs from that cell, before calling dfs create a vector of pairs to store all the island co-ordinate. Pass that vector while calling dfs
Step 3: Dfs will put all the modified island coordinates into the vector.
Step 4: Push that vector into the set.
Step 5: After the loop end, return the size of the set.

                                                            In the Dfs:

Step 1: Check if it is a valid unvisited cell, if not then return.
Step 2: Mark the current cell as visited
Step 3: Push that modified cell into the vector.
Step 4: Call Dfs to the neighbor cells.
  */

class Solution {
  public:
  set<vector<pair<int,int> > >st;
  void dfs(int i,int j,vector<vector<int>>& grid,vector<pair<int,int>>&path,int &sourceRow,int&sourceCol){
    if(i<0 || i>=grid.size()||j<0 || j>=grid[0].size() || grid[i][j]==0) return;
    
    grid[i][j]=0;
    int currRow=i-sourceRow;
    int currCol=j-sourceCol;
    path.push_back({currRow,currCol});
    
    dfs(i+1,j,grid,path,sourceRow,sourceCol);
    dfs(i-1,j,grid,path,sourceRow,sourceCol);
    dfs(i,j+1,grid,path,sourceRow,sourceCol);
    dfs(i,j-1,grid,path,sourceRow,sourceCol);
}
    int countDistinctIslands(vector<vector<int>>& grid) {
         int row=grid.size();
         int col=grid[0].size();
         
          for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                vector<pair<int,int>>path;
                if(grid[i][j]==1){
                    dfs(i,j,grid,path,i,j);
                    st.insert(path);
                }
            }
        }
        return st.size();
    }
};
