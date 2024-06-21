
int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int maxSumOne;
        int windowSumHavingOne=0;
        int s=0;
        int e=minutes-1;
        int ans=0;
        //sum of customers when owner was grumpy
        for(int i=0;i<minutes;i++){
             if(grumpy[i]==1) windowSumHavingOne+=customers[i];
        }
        
        maxSumOne=windowSumHavingOne;
        while(s<n&&e<n-1){
            if(grumpy[s]==1)windowSumHavingOne-=customers[s];
            if(grumpy[e+1]==1)windowSumHavingOne+=customers[e+1];
            s++;
            e++;
            maxSumOne=max(windowSumHavingOne,maxSumOne);
        }
        //sum of all customers when owner was not grumpy
        for(int i=0;i<n;i++){
            if(grumpy[i]==0)ans+=customers[i];
        }
        ans+=maxSumOne;
        return ans;
    }
