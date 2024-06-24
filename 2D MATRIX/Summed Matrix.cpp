//mathematical question
//visualise by seeing the example test cases and try to find the pattern
long long sumMatrix(long long n, long long q) {
        // code here
        
        if(q<=n+1)return q-1;
        if(q>n*2)return 0;
        return (n*2)-q+1;
    }
