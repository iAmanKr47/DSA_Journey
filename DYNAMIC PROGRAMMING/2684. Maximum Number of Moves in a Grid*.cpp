
int maxMoves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        int result=0;
        //traverse from top to bottom of extreme and then move right
        for(int j=1;j<n;j++){
            for(int i=0;i<m;i++){
                 int maxi=-1;
                 //if previous column exist then only check
                if(j-1>=0){
                //left upper cell
                if(i-1>=0 && grid[i-1][j-1]<grid[i][j])maxi=max(maxi,dp[i-1][j-1]);

                //left cell
                if(grid[i][j-1]<grid[i][j])maxi=max(maxi,dp[i][j-1]);
                
                //left bottom cell
                if(i+1<m&&grid[i+1][j-1]<grid[i][j])maxi=max(maxi,dp[i+1][j-1]);
                }
                if(j==0 && maxi==-1)dp[i][j]=0;//only for first column 
                else if(j!=0 && maxi==-1) dp[i][j]=-1;
                else dp[i][j]=1+maxi;
                result=max(result,dp[i][j]);
            }
        }
        return result;
    }
