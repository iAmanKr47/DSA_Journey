class Solution {
    public void setMatrixZeroes(int[][] mat) {
        int m=mat.length;
        int n=mat[0].length;
        boolean firstRow=false;
        boolean firstColumn=false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&mat[i][j]==0){
                    firstRow=true;
                }
                if(j==0&&mat[i][j]==0){
                    firstColumn=true;
                }
                if(mat[i][j]==0){
                    mat[0][j]=0;
                    mat[i][0]=0;
                }
            }
        }
        
       for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (mat[i][0] == 0 || mat[0][j] == 0) {
                    mat[i][j] = 0;
                }
            }
        }
       
        if(firstRow==true){
            for(int j=0;j<n;j++){
                mat[0][j]=0;
            }
        }
        if(firstColumn==true){
            for(int i=0;i<m;i++){
                mat[i][0]=0;
            }
        }
    }
}
