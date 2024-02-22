int mod=1e9+7;
    int solve(int i,int j,string &s,string &t,vector<vector<int>>&dp){
        if(j==t.size()){
            return 1;
        }
        if(i>=s.size()) return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        if(s[i]==t[j]){
            int pick=solve(i+1,j+1,s,t,dp)%mod;
            int notPick=solve(i+1,j,s,t,dp)%mod;
            ans=(pick + notPick)%mod;
        }
        else  ans= solve(i+1,j,s,t,dp)%mod;
        
        dp[i][j]=ans;
        return ans;

    }
    int subsequenceCount(string s, string t)
    {
        int n=s.size();
        int m=t.size();
      vector<vector<int>>dp(n,vector<int>(m,-1));
      return solve(0,0,s,t,dp);
    }
