int findMin(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int s=0;
        int e=nums.size()-1;
        int mid;
        int mini=INT_MAX;
        while(s<=e){
           mid=s+(e-s)/2;
           //EXTRA CHECK FOR THIS QUES AS IT CONATAINS THE DUPLICATE
           if(nums[mid]==nums[s] &&nums[mid]==nums[e]){
             mini=min(mini,nums[s]);
            s++;
            e--;
            continue;
           }
           //if left part is sorted find minimum from left part i,e nums[s]
           if(nums[s]<=nums[mid]){
            mini=min(mini,nums[s]);
            s=mid+1;
           }
           else{
            mini=min(mini,nums[mid]);
            e=mid-1;
           }
        }
        return mini;
