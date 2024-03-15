//multiply prefixsum and suffixsum of a particular index

vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefixSum(n);
        int prefixProduct=1;
        for(int i=0;i<n;i++){
            prefixSum[i]=prefixProduct;
            prefixProduct*=nums[i];
        }
       
        int suffixProduct=1;
         for(int i=n-1;i>=0;i--){
           prefixSum[i]*=suffixProduct;
            suffixProduct*=nums[i];
        } 
       
        return prefixSum;
    }
