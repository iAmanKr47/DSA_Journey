int gameOfXor(int N , int A[]) {
        int ans=0;
        if(N%2==0)
        return 0;
        for(int i=0;i<N;i+=2)
        {
            ans^=A[i];
        }
        return ans;
    }
