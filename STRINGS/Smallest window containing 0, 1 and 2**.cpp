int smallestSubstring(string s) {
        // Code here
        int minSize=INT_MAX;
        int cnt0=-1,cnt1=-1,cnt2=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0')cnt0=i;
            else if(s[i]=='1')cnt1=i;
            else cnt2=i;
            
            if(cnt0!=-1&&cnt1!=-1&&cnt2!=-1){
            int mini=min(cnt0,min(cnt1,cnt2));
            int maxi=max(cnt0,max(cnt1,cnt2));
            
            minSize=min(minSize,maxi-mini+1);
            
            }
            
        }
        if(minSize==INT_MAX)return -1;
        
        return minSize;
            
    }
