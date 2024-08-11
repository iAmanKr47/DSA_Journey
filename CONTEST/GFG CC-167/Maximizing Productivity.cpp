// https://practice.geeksforgeeks.org/contest/gfg-weekly-167-rated-contest/problems
// PICK - NOT PICK APPROACH

class Solution {
  public:
  int maxi=0;
  void solve(int index,int sum1,int &totalSum,int &n,vector<int> &productivity,vector<int>&dp){
      if(index>=n){
          maxi=max(maxi,sum1*(totalSum-sum1));
          dp[sum1]=maxi;
          return;
      }
      if(dp[sum1]!=-1)return ;
      
      solve(index+1,sum1+productivity[index],totalSum,n,productivity,dp);
      solve(index+1,sum1,totalSum,n,productivity,dp);
  }
    int getMaxProductivity(int n, vector<int> &productivity) {
        int sum1=0;
        int sum2=0;
        int totalSum=0;
        for(auto i:productivity)totalSum+=i;
        vector<int>dp(totalSum+1,-1);
        solve(0,sum1,totalSum,n,productivity,dp);
        return maxi;
    }
};


//code 2 :Same with return type of int

class Solution {
  public:
  int maxi=0;
  int solve(int index,int sum1,int &totalSum,int &n,vector<int> &productivity,vector<int>&dp){
      if(index>=n){
          return sum1*(totalSum-sum1);
      }
      if(dp[sum1]!=-1)return dp[sum1];
      
      int take=solve(index+1,sum1+productivity[index],totalSum,n,productivity,dp);
      int notTake=solve(index+1,sum1,totalSum,n,productivity,dp);
      return dp[sum1]=max(take,notTake);
  }
    int getMaxProductivity(int n, vector<int> &productivity) {
        int sum1=0;
        int totalSum=0;
        for(auto i:productivity)totalSum+=i;
        vector<int>dp(totalSum+1,-1);
        return solve(0,sum1,totalSum,n,productivity,dp);

    }
};
