 int leastInterval(vector<char>& tasks, int n) {
        int size=tasks.size();
        if(size==1)return 1;
        vector<int>freq(26,0);
        int maxFreq=0;
        int elementCount=0;
        for(auto i: tasks) {
            freq[i-'A']++;
            maxFreq=max(maxFreq,freq[i-'A']);
         }
         for(auto i:freq){
            if(i==maxFreq) elementCount++;
         }
         //formula 
         int ans= maxFreq+ n*(maxFreq-1) + elementCount-1;
         ans=max(ans,size);
         return ans;
         }
