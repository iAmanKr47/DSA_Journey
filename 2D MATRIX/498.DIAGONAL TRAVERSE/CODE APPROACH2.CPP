vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int>ans;
        
        int m=mat.size();
        int n=mat[0].size();
        bool toReverse=false;
        //upper triangle
        
        for(int i=0;i<m;i++){
             int row=i;
             int col=0;
             vector<int>temp;
             while(row>=0&&col<n){
                temp.push_back(mat[row][col]);
                row--;
                col++;
             }
             if(toReverse){
                 reverse(temp.begin(),temp.end());
                 toReverse=false;
             }
             else toReverse=true;
             for(auto ele:temp)
             ans.push_back(ele);

        }
        //lower triangle 
        for(int j=1;j<n;j++){
            int row=m-1;
            int col=j;
            vector<int>temp;
             while(row>=0&&col<n){
                temp.push_back(mat[row][col]);
                row--;
                col++;
             }
             if(toReverse){
                 reverse(temp.begin(),temp.end());
                 toReverse=false;
             }
             else toReverse=true;
             for(auto ele:temp)
             ans.push_back(ele);
        }
        return ans;
    }
