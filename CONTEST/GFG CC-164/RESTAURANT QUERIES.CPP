//TLE SOLUTION T.C: O(q*n)


class Solution {
  public:
    vector<long long> sumofItems(int n, vector<int> &prices, int q,
                                 vector<vector<int>> &queries) {
       long long sum=0;
       map<long long ,int>mp;
       vector<long long>ans;
       for(auto i:prices){
           mp[i]++;
           sum+=i;
       }
       
       for(auto q:queries){
           if(q[0]==2 && mp.find(q[1])!=mp.end()){
               int prevCnt=mp[q[1]];
               mp.erase(q[1]);
               mp[q[2]]+=prevCnt;
               sum+=(q[2]-q[1])*prevCnt;
               
           }
           else if(q[0]==1 ){
               sum=0;
               for (auto it = mp.rbegin(); it!= mp.rend();it++) {
                   auto key=it->first;
                   int cnt=it->second;
                   long long newKey=key+q[1];
                   sum+=newKey*cnt;
                   mp.erase(key);
                   mp[newKey]=cnt;
                   
               }
           }
           ans.push_back(sum);
       }
       return ans;
    }
};
