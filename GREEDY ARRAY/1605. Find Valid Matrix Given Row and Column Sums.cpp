//TOPICS: MATRIX ,GREEDY
vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int r=rowSum.size();
        int c=colSum.size();
        vector<vector<int>>ans(r,vector<int>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int mini=min(rowSum[i],colSum[j]);
                ans[i][j]=mini;
                rowSum[i]-=mini;
                colSum[j]-=mini;
            }
        }
        return ans;
    }
