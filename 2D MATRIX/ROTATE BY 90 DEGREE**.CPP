//FIND TRANSPOSE OF THE MATRIX
//REVERSE THE COLUMNS 

void rotate(vector<vector<int> >& matrix) {
    // Your code goes here
    
    //transpose of a matrix 
      int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=i;j<m;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    
    
    //reverse the columns of the transposed matrix
      for(int i=0;i<n;i++){
            int low=0;
            int high=n-1;
            while(low<=high){
                swap(matrix[i][low],matrix[i][high]);  
                low++;
                high--;
            }
        }
}
