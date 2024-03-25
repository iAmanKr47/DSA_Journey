vector<int> findDuplicates(vector<int>& nums) {
       vector<int>ans;
       for(int i=0;i<nums.size();i++){
        int ind=abs(nums[i]);//take absolute value so that  we can to access the index in future
        if(nums[ind-1]<0)ans.push_back(ind);// ind-1 is done cz of zero based indexing
        nums[ind-1]=-nums[ind-1]; 
       } 
       return ans;
    }
