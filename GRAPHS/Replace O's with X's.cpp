class Solution{
public:
void solve(int i,int j,vector<vector<char>>&mat,vector<vector<int>>&vis){
    if(i>=mat.size()||j>=mat[0].size()||mat[i][j]=='X' || vis[i][j]==1){
        return ;
    }
    vis[i][j]=1;
    solve(i,j+1,mat,vis);
    solve(i,j-1,mat,vis);
    solve(i+1,j,mat,vis);
    solve(i-1,j,mat,vis);
    
}
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
       vector<vector<int>>vis(n,vector<int>(m,-1));
       vector<vector<char>>ansMatrix(n,vector<char>(m));
      // the 'O' cells which are at boundary and all 'O' cells which are connnecting with these boundary '0' mark them visited
      //by doing it ensures the  left over 'O' cells will be surrounded by X by all four direction
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if( (i==0||j==0||i==n-1||j==m-1) && (mat[i][j]=='O' && vis[i][j]==-1) )
                solve(i,j,mat,vis);
           }
       }
      //now those 'O' which are at boundary or those '0' which are in contact with boundary '0' would have marked as visited in vis matrix
      //now flip those cell having 'O'&& which haven't been visited yet i,e -1
      
      for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
              if(mat[i][j]=='O' && vis[i][j]==-1){
                ansMatrix[i][j]='X'; 
              }
              else{
                  ansMatrix[i][j]=mat[i][j];
              }
            }
        }
       return ansMatrix;
    }
};
