// Striver : https://takeuforward.org/data-structure/dynamic-programming-ninjas-training-dp-7/
class Solution {
  public:
  
  int solve(vector<vector<int>>& arr, vector<vector<int>>&dp,int todayIndex,int lastDayIndex){
      //bottom up approach
      //base case
      if(todayIndex==0){
          int maxi=0;
          for(int i=0;i<3;i++)if(i!=lastDayIndex) maxi=max(maxi,arr[todayIndex][i]);
          return maxi;
      }
      //further processing 
      int maxiSum=0;
       for(int i=0;i<3;i++){
           
           if(i!=lastDayIndex) {
                int points=arr[todayIndex][i]+solve(arr,dp,todayIndex-1,i);//total points we would have gained if we had taken a particular exercise today 
                maxiSum=max(maxiSum,points);
            }
       }
          return maxiSum;
  }
    int maximumPoints(vector<vector<int>>& arr, int n) {
        return solve(arr,n-1,3);
    }
};


// MEMOISATION

class Solution {
  public:
  int solve(vector<vector<int>>& arr, vector<vector<int>>&dp,int todayIndex,int lastDayIndex){
      //bottom up approach
      //base case
      if(todayIndex==0){
          int maxi=0;
          for(int i=0;i<3;i++)if(i!=lastDayIndex) maxi=max(maxi,arr[todayIndex][i]);
          return dp[todayIndex][lastDayIndex]=maxi;
      }
      //further processing 
      if(dp[todayIndex][lastDayIndex]!=-1)return dp[todayIndex][lastDayIndex];
      
      int maxiSum=0;
       for(int i=0;i<3;i++){
           
           if(i!=lastDayIndex) {
                int points=arr[todayIndex][i]+solve(arr,dp,todayIndex-1,i);//total points if we had taken a particular exercise today 
                maxiSum=max(maxiSum,points);
            }
       }
          return dp[todayIndex][lastDayIndex]=maxiSum;
  }
    int maximumPoints(vector<vector<int>>& arr, int n) {
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return solve(arr,dp,n-1,3);
    }
};



//TABULATION METHOD

int maximumPoints(vector<vector<int>>& arr, int n) {
        //tabulation 
        //bottom up
        vector<vector<int>>dp(n,vector<int>(3,0));
        int maxi=0;
        dp[n-1][0]=arr[n-1][0];
        dp[n-1][1]=arr[n-1][1];
        dp[n-1][2]=arr[n-1][2];
        for(int day=n-2;day>=0;day--){
            dp[day][0]=arr[day][0]+ max(dp[day+1][1],dp[day+1][2]);
            dp[day][1]=arr[day][1]+ max(dp[day+1][0],dp[day+1][2]);
            dp[day][2]=arr[day][2]+ max(dp[day+1][0],dp[day+1][1]);
            
        }
        maxi=max(maxi,max(dp[0][0],max(dp[0][1],dp[0][2])));
        return maxi;
    }
