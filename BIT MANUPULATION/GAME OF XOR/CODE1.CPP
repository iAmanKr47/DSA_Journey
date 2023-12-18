int gameOfXor(int n , int a[]) {
        int ans=0;
        if(n%2==0)
        return 0;
        for(int i=0;i<n;i++)
        {
             int count = (n-i)*(i+1);
             if(count%2) ans= ans ^ a[i];
        }
        return ans;
    }
