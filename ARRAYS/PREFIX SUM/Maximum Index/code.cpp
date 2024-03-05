APPROACH 1: SUFFIX-MAX /RIGHT MAX
  
int maxIndexDiff(int a[], int n) 
    { 
        
         vector<int>rmax(n);
         rmax[n-1]=a[n-1];
         for(int i=n-2;i>=0;i--){
             rmax[i]=max(rmax[i+1],a[i]);
         }
         
         int i=0,j=0,maxdiff=INT_MIN;
         while(i<n && j<n){
             if(rmax[j]>=a[i]){
                 maxdiff=max(maxdiff,j-i);
                 j++;
             }else{
                 i++;
             }
         }
         return maxdiff;
    }

APPROACH 2: TWO POINTER APPRAOCH ( TEST CASE PASSED 1120/1121)
  
 int maxIndexDiff(int a[], int n) 
    { 
 
        if(n==1) return 0;
        if(a[0]<=a[n-1]) return n-1;
        
        int s=0;
        int e=n-1;
        int maxiAns=-1;
        while(s<e && s<n && e<n){
            
            while(s<e&& a[s]>a[e]){
                e--;
            }
            maxiAns=max(maxiAns,e-s);
            s++;
            while(s<n && a[s-1]<a[s])s++;
            
            int k=n-1;
            while(k>e &&a[s]>a[k]){
                k--;
            }
            if(k>e) maxiAns=max(maxiAns,k-s);
            e=k;
            if(s<=e){
                s++;
                e=n-1;
            } 
            
        }
        
        return maxiAns;  
    }
