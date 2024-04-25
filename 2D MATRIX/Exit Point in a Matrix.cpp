vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        int row=0;
        int col=0;
        int direction=0; //direction 0->right,1->bottom,2->left,3->top
        while(row>=0 &&row<n && col>=0&&col<m){
            if(matrix[row][col]==1){
                matrix[row][col]=0;
                direction++;
            }
            if(direction%4==0)col++; //right
            else if(direction%4==1) row++; //bottom
            else if(direction%4==2) col--; //left
            else row--; //top
        }
        if(row<0)return {0,col};
        else if(row>=n) return {n-1,col};
        else if(col<0) return {row,0};
        return {row,m-1};
    }
