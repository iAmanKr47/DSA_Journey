//APPROACH 1

class Solution{
	public:
	vector<string>ans;
	void solve(int i,string &s,string temp){
	    if(i>=s.size()){
	        if(temp.size()>0) //as we dont want empty string in the ans so just check
	        ans.push_back(temp); 
	        return ;
	    }
	    
	    solve(i+1,s,temp+s[i]); //pick
	    solve(i+1,s,temp); //not pick
	    
	    
	}
		vector<string> AllPossibleStrings(string s){
		   solve(0,s,"");
		   
	       sort(ans.begin(),ans.end());
		   return ans;
		}
};

//APPROACH 2:

class Solution{
    private:
        void solve(int ind, string &s, string &ds, vector<string> &ans){
            if(ind >= s.size()){
                if(ds.size() > 0)
                ans.push_back(ds);
                return;
            }
            
            ds.push_back(s[ind]);
            solve(ind + 1, s, ds, ans);
            ds.pop_back();
            solve(ind + 1, s, ds, ans);
        }
    
public:
vector<string> AllPossibleStrings(string s){
    vector<string> ans;
    string ds;
    solve(0, s, ds, ans);
    sort(ans.begin(), ans.end());
    return ans;
}
};
