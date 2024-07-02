
long long ANDequalOR(int n, vector<int> arr) {
        long long ans=0;
        int i=0;
        while(i<n){
            long long  cnt=1;
            int ele=arr[i];
            i++;
            while(i<n && arr[i]==ele){
                cnt++;
                i++;
            }
            ans+=((cnt+1)*cnt)/2;
        }
        return ans;
    }
