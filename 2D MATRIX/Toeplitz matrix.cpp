//approach 1
bool isToeplitz(vector<vector<int>>& mat) {
    // code here
    int m=mat.size();
    int n=mat[0].size();
    //check for corresponding diagonal starting from each element of first row
    for(int j=0;j<n;j++){
        int ele=mat[0][j];
        int r=1;
        int c=j+1;
        while(r<m&&c<n){
            if(mat[r][c]!=ele)return false;
            r++;
            c++;
        }
    }
    //check same for corresponding diagonal starting from each element of first col
    for(int i=0;i<m;i++){
        int ele=mat[i][0];
        int r=i+1;
        int c=1;
        while(r<m&&c<n){
            if(mat[r][c]!=ele)return false;
            r++;
            c++;
        }
    }
    return true;
}



//approach 2:
bool isToeplitz(vector<vector<int>>& mat) {
    // Check all diagonal lines starting from the top row
    int n = mat.size();
    int m = mat[0].size();
    
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            // check if each index is equal to its
            // diagonally upper index if not return false
            if (mat[i][j] != mat[i - 1][j - 1])
                return false;
        }
    }
    return true;
}
