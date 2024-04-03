bool solve(vector<vector<char>>& board, string &word,int &m,int &n,int row,int col,int index,vector<vector<bool>> &visited){
    if(index>=word.size()) return true;
    if(row<0 || row>=m || col<0 || col>=n)return false;
    if(visited[row][col])return false;
    if(word[index]!=board[row][col])return false;
    visited[row][col]=true;
    if(solve(board,word,m,n,row+1,col,index+1,visited) || solve(board,word,m,n,row-1,col,index+1,visited)|| solve(board,word,m,n,row,col+1,index+1,visited) || solve(board,word,m,n,row,col-1,index+1,visited) ) return true;
     visited[row][col]=false;
     return false;
    
}
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(word[0]==board[i][j]){
                    if (solve(board,word,m,n,i,j,0,visited))
                    return true;
                }
            }
        }
        return false;
    }
