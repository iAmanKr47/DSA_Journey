//RECURSION
class Solution {
public:
int solve(int i,string &s,unordered_set<string>&dict,int&n){
    if(i>=n)return 0;
    int breakPoint=1+solve(i+1,s,dict,n);
    int include=INT_MAX;
    for(int j=i;j<n;j++){
        string temp=s.substr(i,j-i+1);
        if(dict.count(temp)){
           include=min(include,solve(j+1,s,dict,n));
        }
    }
    return min(breakPoint,include);
}
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string>dict;
        int n=s.size();
        for(auto s:dictionary){
           dict.insert(s);
        }
        return solve(0,s,dict,n);
    }
};
