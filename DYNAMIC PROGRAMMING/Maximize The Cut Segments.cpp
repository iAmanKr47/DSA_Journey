//MEMOISATION
class Solution
{
    public:
    int solve(int n, int &x, int &y, int &z,vector<int>&dp){
        
        if(n==0)return 0;
        if(n<0)return INT_MIN;
        if(dp[n]!=-1)return dp[n];
        
        int ans1=solve(n-x,x,y,z,dp);
        int ans2=solve(n-y,x,y,z,dp);
        int ans3=solve(n-z,x,y,z,dp);
        return dp[n]=1+max(ans1,max(ans2,ans3));
        
    }
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
       vector<int>dp(n+1,-1);
       return max(0,solve(n,x,y,z,dp));
    }
};
