//RECURSSIVE SOLUTION - TLE 
//OPTIMISE USING DP

class Solution {
public:
long long sum=0;
    long long numberOfPath(int n, int k, vector<vector<int>> &arr){
        
        long res=count(0,0,0,arr,n,k);
        return res;
    }
    long long count(int sum,int i,int j,vector<vector<int>> &arr,int n,int k)
    {
     if(i==n || j==n)
     return 0;
     sum+=arr[i][j];
     if(sum==k && (i==n-1 && j==n-1))
     {
         return 1;
     }
     if(sum>k)
     return 0;
     
     long long a=count(sum,i+1,j,arr,n,k);
     long long b=count(sum,i,j+1,arr,n,k);
     
     return a+b;
     
    }
};
