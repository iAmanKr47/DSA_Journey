int getMinDiff(int arr[], int n, int k) {
        sort(arr,arr+n);
        
        int smallest=arr[0]+k;
        int largest=arr[n-1]-k;
        
        int diff=arr[n-1]-arr[0];
        
        int maxEle,minEle;
        for(int i=0;i<n-1;i++){
             minEle=min(smallest,(arr[i+1]-k));
             maxEle=max(largest,(arr[i]+k));
            
            if(minEle>=0) diff=min((maxEle-minEle),diff);
        }
        return diff;
    }
