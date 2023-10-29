int maxoccourence(int arr[], int n, int k)
        {
            int maxOcc=0;
            int ans=-1;
            sort(arr,arr+n);
            for(int i=0;i<n;i++){
               int num=arr[i];
               int cnt=0;
               while(num>0){
                   int digi=num%10;
                   if(digi==k) cnt++;
                   num/=10;
                   }
                if(cnt>maxOcc)
                {
                    maxOcc=cnt;
                    ans=arr[i];
                }
                
            }
                
    return ans;
        }
