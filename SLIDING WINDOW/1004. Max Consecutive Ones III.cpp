 int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        int n=nums.size();
        int cntZeroes=0;
        int maxi=0;
        while(r<n){
            if(nums[r]==0)cntZeroes++;
            if(cntZeroes>k){ //shirinking phase
              while(nums[l]!=0)l++;
              cntZeroes--;
              l++;  
            }
            maxi=max(maxi,r-l+1);
            r++; //expanding phase

        }
        return maxi;
    }
