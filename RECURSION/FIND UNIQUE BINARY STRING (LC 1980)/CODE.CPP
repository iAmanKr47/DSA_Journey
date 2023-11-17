class Solution {
public:
 string ans="";
 set<string>st;
  void solve(string str,int &n){
    if(str.size()==n){
       if(st.find(str)==st.end()&&ans=="") ans+=str;   
    return;
    }
    solve(str+'0',n);
    solve(str+'1',n);
    return;
}
    string findDifferentBinaryString(vector<string>& nums) {
        string str="";
        for(auto s:nums)
        st.insert(s);
        int n=st.size();
        solve("",n);
        return ans;
    }
};
