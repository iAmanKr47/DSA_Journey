//CONTEST LC WC :426

int getLargestOutlier(vector<int>& nums) {
        int sum=0;
        unordered_map<int,int>mp;
        int outlier=-1001;
        for(auto i:nums){
            sum+=i;
            mp[i]++;
        }
        //now check every element as potential outlier
        for(int i=0;i<nums.size();i++){
            sum-=nums[i];
            mp[nums[i]]--;
            if(sum%2==0 && mp.find(sum/2)!=mp.end() && mp[sum/2]>0)outlier=max(outlier,nums[i]); //if remaining sum can be divided in half and that half value is prsent in the array.
            mp[nums[i]]++;
            sum+=nums[i];
        }
        return outlier;
    }
