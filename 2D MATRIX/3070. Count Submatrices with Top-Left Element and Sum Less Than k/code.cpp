//TOPIC : PREFIXSUM IN 2D MATRIX OR   ( TABULATION TECHNIQUE IN DP)

//CODE 1:

int countSubmatrices(vector<vector<int>>& grid, int k) {
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;
    //prefixsum first row   
    
        for(int j=1;j<n;j++){
           grid[0][j]+=grid[0][j-1];
           
        }
        //prefixsum first col
        for(int i=1;i<m;i++){
           grid[i][0]+=grid[i-1][0];
        }
    
    //prefix remaining matrix
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
           grid[i][j]+=grid[i][j-1]+grid[i-1][j]-grid[i-1][j-1]; 
        }
    }
    //check for the conditon
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
          if(grid[i][j]<=k)ans++;
        }
    }

    return ans;
}


//CODE 2: CLEAN CODE

int countSubmatrices(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();
        int res = 0; 

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(i>0) grid[i][j] += grid[i-1][j];
                if(j>0) grid[i][j] += grid[i][j-1];
                if(i>0 && j>0) grid[i][j] -= grid[i-1][j-1];

                if(grid[i][j] <= k) res++;
                else break;
            }
        }

        return res; 
    }
