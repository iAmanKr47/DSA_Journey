int MinSize(vector<int> arr, int n) {
        if(n==1)return 1;
        int maxi=INT_MIN;
        int cnt=0;
        unordered_map<int,int>mp;
        for(auto i:arr){
            mp[i]++;
            maxi=max(maxi,mp[i]);
        }
        if(maxi==1 && n%2==0)return 0;
        else if(maxi==1 && n%2!=0)return 1;
        priority_queue<int>pq;
        for(auto i:mp)pq.push(i.second);
        while(pq.size()>1){
            auto front1=pq.top();
            pq.pop();
            auto front2=pq.top();
            pq.pop();
            int updateCnt=front1-front2;
            if(updateCnt>0)pq.push(updateCnt);
        }
        if(pq.size()==0)return 0;
        return pq.top();
        
    }
