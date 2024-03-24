// MATHS+ GREEDY APPROACH
// Video Link :https://youtu.be/6MigDs3Q5Ks?t=770&si=WYQJCmx008-J3P7I

int minOperations(int k) {
        if(k==1) return 0;
        int ans=k;
        for(int i=1;i<=k/2;i++){
            int op=(i-1)+ ceil(double(k)/double(i) -1);
            ans=min(ans,op);
        }
        return ans;
    }
