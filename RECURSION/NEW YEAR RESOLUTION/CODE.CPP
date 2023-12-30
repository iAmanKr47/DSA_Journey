bool helper(int i,int sum,int arr[],int &n)
    {
        if((sum>0)&&(sum%20==0 || sum%24==0 || sum==2024))
            return true;
        if(i>=n)
            return false;
        return helper(i+1,sum+arr[i],arr,n)||helper(i+1,sum,arr,n);
    }
    int isPossible(int N , int coins[]) 
    {
           return helper(0,0,coins,N);
    }
