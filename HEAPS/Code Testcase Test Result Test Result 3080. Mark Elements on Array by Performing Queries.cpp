vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<long long >ans;
        int m=queries.size();
        int n=nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        unordered_set<int>visited;
        long long totalSum=0;
        
        for(int i=0;i<n;i++){
            pq.push(make_pair(nums[i],i));
            totalSum+=nums[i];
            
        }
        //whenever mark a new element as visited subtract that element from the totalSum 
        for(auto i:queries){
            //mark element as visited only if it is not marked earlier as visited
            if(visited.find(i[0])==visited.end()){
                visited.insert(i[0]);
                totalSum-=nums[i[0]]; //imp step
            }
            
            int k=i[1];
            
            while(k && pq.size()){
                 auto topPair=pq.top();
                 pq.pop();
                if(visited.find(topPair.second)==visited.end()){
                    totalSum-=topPair.first; //imp step
                    visited.insert(topPair.second);
                    k--;
                }
            }
            ans.push_back(totalSum);
            
        }
        return ans;
    }
