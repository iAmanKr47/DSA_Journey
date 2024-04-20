// matrix + dfs+ recurssion

void dfs(int i,int j,vector<vector<int>>& land,int &r2,int &c2){
    if(i<0||i>=land.size() || j<0||j>=land[0].size() || land[i][j]==0){
        return;
    }
    land[i][j]=0;
    r2=max(r2,i);
    c2=max(c2,j);
    dfs(i+1,j,land,r2,c2);
    dfs(i-1,j,land,r2,c2);
    dfs(i,j+1,land,r2,c2);
    dfs(i,j-1,land,r2,c2);
}
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>>ans;
        int row=land.size();
        int col=land[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
               if(land[i][j]==1){
                int r1=i;
                int c1=j;
                int r2=i;
                int c2=j;
                dfs(i,j,land,r2,c2);
                ans.push_back({r1,c1,r2,c2});
               }
               
            }
        }
        return ans;
    }
