
class Solution {
  public:
    int maximumBattalions(int N, vector<string> &names) {
        unordered_map<string,int>mp;
        //storing last index of occurence of a string 
       for(int  i=0;i<N;i++){
         mp[names[i]]=i;
        }
    
        int maxFinish=0;
        int cnt=0;
        for(int i=0;i<N;i++){
            maxFinish=max(mp[names[i]],maxFinish);
            if(maxFinish==i)cnt++;
        }
         return cnt;
    }
};
