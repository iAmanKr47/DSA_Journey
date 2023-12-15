vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int  m=grid.size();
        int  n=grid[0].size();
       vector<int> row(m);
       vector<int> col(n);
        vector<vector<int>> diff( m , vector<int> (n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    row[i] += grid[i][j];
                    col[j] += grid[i][j];
                }
            }
        }
       for(int i=0;i<m;i++){ 
          for(int j=0;j<n;j++){
        int onesRow=row[i];
        int onesCol=col[j];
        int zerosRow=row[i]-n;
        int zerosCol=col[j]-m;
         diff[i][j] = ( 2 * row[i] - m  ) + ( 2 * col[j] - n);
    }
       }
       return diff;
    }
