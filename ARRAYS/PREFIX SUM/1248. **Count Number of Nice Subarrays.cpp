
//prefixSum typical question
//refer 930. Binary Subarrays With Sum 
//do above ques before this 
int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>prefixSum(n);
        for(int i=0;i<n;i++){
           if(nums[i]%2==0)prefixSum[i]=0;
           else prefixSum[i]=1;
        }
        unordered_map<int,int>mp;
        int sum=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            sum+=prefixSum[i];
            if(sum==k)cnt++;
            if(mp.find(sum-k)!=mp.end()){
                cnt+=mp[sum-k];
            }
            mp[sum]++;
        }
        return cnt;
    
    }
