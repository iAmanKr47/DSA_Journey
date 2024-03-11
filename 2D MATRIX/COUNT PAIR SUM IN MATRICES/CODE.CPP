	int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
	{
	    if(mat1[0][0]+mat2[0][0]>x || mat1[n-1][n-1]+mat2[n-1][n-1]<x ) return 0;// if target value less than sum of first element of both the matrix or greater than last elemnt of both the matrix
	    //two pointer approach sr:starting row ,sc:starting col,er:ending row,ec:ending col
	    int sr=0;
	    int sc=0;
	    int er=n-1;
	    int ec=n-1;
	    int cnt=0;
	    while(sr<n && er>=0){
	        if(mat1[sr][sc]+mat2[er][ec]==x) {
	            cnt++;
	            sc++;
	            ec--;
	        }
	        else if(mat1[sr][sc]+mat2[er][ec]>x){
	            ec--;
	        }
	        else sc++;
	        
	        if(sc>=n){
	            sr++;
	            sc=0;
	        }
	        if(ec<0){
	            ec=n-1;
	            er--;
	        }
	        
	    }
	    return cnt;
	    
	}
