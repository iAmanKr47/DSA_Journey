/*
  Here are some small tips:

The answer range should be from Min to Max of the bloomDay.
> To handle overflow and early exits. use (long) check if m*k > bloomDay.length.
> Create a helper function to check if the current day in the given range can gather m flowers. Based on the return value -> do the binary search.

*/

class Solution {
public:
bool checkIsPossible(vector<int>& bloomDay, int &m, int &k,int &days){
    int cnt=0;
      for(int i=0;i<bloomDay.size();i++){
        int tempCnt=0;
          if(bloomDay[i]<=days){
            while(i<bloomDay.size()&&bloomDay[i]<=days){
                 tempCnt++;
                if(tempCnt>=k){
                 cnt++;
                 break;
                }
                i++;
               
            }
          }
          if(cnt>=m)return true;
      }  
      return false;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((long)m*k>n) return -1;
        int ans;
        vector<int>v(bloomDay.begin(),bloomDay.end());
        sort(v.begin(),v.end());
        ans=v[n-1];
        if(m*k==n )return v[n-1];
        int s=0;
        int e=n-1;
        while(s<=e){
           int mid=s+(e-s)/2;
           int days=v[mid];
           if(checkIsPossible(bloomDay,m,k,days)){
            ans=min(ans,days);
            e=mid-1;
           }
           else{
            s=mid+1;
           }
        }
        return ans;
    }
};
