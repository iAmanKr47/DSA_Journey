int trap(vector<int>& height) {
        int n=height.size();
        int ans=0;
        vector<int>prefixSum(n);
        vector<int>suffixSum(n);
        prefixSum[0]=height[0];
        suffixSum[n-1]=height[n-1];
        for(int i=1;i<n;i++) prefixSum[i]=max(prefixSum[i-1],height[i]);
        for(int i=n-2;i>=0;i--) suffixSum[i]=max(suffixSum[i+1],height[i]);
        for(int i=0;i<n;i++){
            ans+=min(prefixSum[i],suffixSum[i])-height[i];
        }
        return ans;
    }
