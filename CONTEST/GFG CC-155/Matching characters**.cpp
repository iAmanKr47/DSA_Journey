//TOPIC: STRING + CONCEPT OF ADJENCY LIST

class Solution {
  public:
    vector<int> matchingCnt(int n, vector<string>& x) {
        vector<int>ans;
       vector<vector<int>>freq(2e5+4,vector<int>(26,0));//index and freq array of 26 letters
        for(auto st:x){
            for(int i=0;i<st.size();i++)
            freq[i][st[i]-'a']++;
        }
        
        for(auto st:x){
            int sum=0;
            for(int i=0;i<st.size();i++){
            freq[i][st[i]-'a']--;
            sum+=freq[i][st[i]-'a'];
            }
            ans.push_back(sum);
        }
        return ans;
    }
};
