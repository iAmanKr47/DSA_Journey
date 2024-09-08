long long findMaximumScore(vector<int>& nums) {
        long long score=0;
        int n=nums.size();
        if(n==1)return 0;
        int currIndex=0;
        int i=0;
        while(i<n){
            while(i<n && nums[i]<=nums[currIndex])i++;
            //now i at that index which is either max or index=n;
            if(i==n)i--;
            score+=(long long )(i-currIndex)*nums[currIndex];
            currIndex=i;
            if(currIndex==n-1)return score;
        }
        return score;
    }
