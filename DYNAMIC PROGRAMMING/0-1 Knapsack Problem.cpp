//MEMOIZATION
    int solve(vector<int>& wt, vector<int>& val,int index,int w,vector<vector<int>>&dp){
        if(index==0){
            if(wt[index]<=w)return val[index];
            else return 0;
        }
        if(dp[index][w]!=-1)return dp[index][w];
        int take=INT_MIN;
        if(w-wt[index]>=0) take=val[index]+solve(wt,val,index-1,w-wt[index],dp);
        int notTake=solve(wt,val,index-1,w,dp);
        return dp[index][w]=max(take,notTake);
        
    }
    int knapSack(int w, vector<int>& wt, vector<int>& val) {
        // Your code here
        
        int n=wt.size();
        vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
        return solve(wt,val,n-1,w,dp);
    }
