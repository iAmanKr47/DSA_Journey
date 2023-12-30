//CODE 1
int kSubstrConcat (int n, string s, int k)
	{
	     if(n%k!=0)
        {
            return 0;
        }
        unordered_map<string,int>mp;
        for(int i=0;i<=n-k;i=i+k){
            string temp = s.substr(i,k);
            mp[temp]++;
        }
      if(mp.size()==1) return 1;
      if(mp.size()>2)return 0;
      
      int cnt1=INT_MAX;
      
      if(mp.size()==2){
         for(auto i:mp){
             cnt1=min(cnt1,i.second);
         } 
      }
       return cnt1==1;
	}

//CODE 2
int kSubstrConcat (int n, string s, int k)
	{
	     if(n%k!=0)
        {
            return 0;
        }
        unordered_map<string,int>mp;
        for(int i=0;i<=n-k;i=i+k){
            string temp = s.substr(i,k);
            mp[temp]++;
        }
      if(mp.size()==1) return 1;
      else if(mp.size()>2)return 0;
      
      else//when mp.size==2
        for(auto it:mp) 
        {
            if(it.second==1 ) return 1;
 
        }
        return 0;
	}

