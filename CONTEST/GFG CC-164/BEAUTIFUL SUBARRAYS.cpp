 long long countSubarrays(int n, vector<int> &arr) {
        long long cnt=0;
        for(int i=0;i<n;i++){
            int mini=INT_MAX;
            int maxi=INT_MIN;
            for(int j=i;j<n && j<i+52;j++){
                mini=min(mini,arr[j]);
                maxi=max(maxi,arr[j]);
                int sum=maxi+mini;
                if(sum%(j-i+1)==0)cnt++;
            }
        }
        return cnt;
    }
