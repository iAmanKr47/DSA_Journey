//code 1:
int minimumArea(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        bool flag=false;
        int sr;
        int er;
        int sc;
        int ec;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    sr=i;
                    flag=true;
                    break;
                }
            }
            if(flag)break;
        }
        //bottom
        flag=false;
        for(int i=r-1;i>=0;i--){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    er=i;
                    flag=true;
                    break;
                }
            }
            if(flag)break;
        }
        //left
        flag=false;
        for(int i=0;i<c;i++){
            for(int j=0;j<r;j++){
                if(grid[j][i]==1){
                    sc=i;
                    flag=true;
                    break;
                }
            }
            if(flag)break;
        }
        //rightto left
        flag=false;
        //left
        for(int i=c-1;i>=0;i--){
            for(int j=0;j<r;j++){
                if(grid[j][i]==1){
                    ec=i;
                    flag=true;
                    break;
                }
            }
            if(flag)break;
        }
        int ans=(er-sr+1)*(ec-sc+1);
        return ans;
    }


//code 2 JAVA CODE : SAME LOGIC AS ABOVE JUST IN LESS NO. OF LINES IN A SINGLE PASS
class Solution {
    public int minimumArea(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        
        int minb = Integer.MAX_VALUE;
        int maxb = Integer.MIN_VALUE;
        int minl = Integer.MAX_VALUE;
        int maxl = Integer.MIN_VALUE;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    minb = Math.min(minb, j);
                    maxb = Math.max(maxb, j);
                    minl = Math.min(minl, i);
                    maxl = Math.max(maxl, i);
                    
                }
            }
        }
        int length = maxl-minl+1;
        int breadth = maxb-minb+1;
        int area = length*breadth;
        
        return area;
    }
}
