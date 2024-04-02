int lengthOfLongestSubstring(string s) {
         if(s.size()==0)return 0;
        unordered_map<char,int>mp; //store character and it's index
        int l=0;
        int r=0;
        int maxLen=1;
        int n=s.size();
        while(r<n){
           if(mp.find(s[r])!=mp.end() && mp[s[r]]>=l ){ //if character is present and it's index is after the index where left pointer is pointing then , left= index of repeated character +1;
            l=mp[s[r]]+1;
           } 
           mp[s[r]]=r;
           maxLen=max(maxLen,r-l+1);
           r++;
        }
    return maxLen;
    }
