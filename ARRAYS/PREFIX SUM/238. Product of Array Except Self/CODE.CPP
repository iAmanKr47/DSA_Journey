                                                          //APPROACH 1
vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        vector<int>prefix(n,1);
        vector<int>suffix(n,1);

        int curr=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]*=curr;
            curr*=nums[i];
        }
        curr=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]*=curr;
            curr*=nums[i];
        }
        for(int i=0;i<n;i++){
            ans.push_back(prefix[i]*suffix[i]);
           
        }
        return ans;
    }


                                                         //APPAROACH 2

vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        int prefixProduct = 1;
        for (int i = 0; i < n; i++) {
            result[i] *= prefixProduct;
            prefixProduct *= nums[i];
        }
        int suffixProduct = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= suffixProduct;
            suffixProduct *= nums[i];
        }
        return result;
    
    }
