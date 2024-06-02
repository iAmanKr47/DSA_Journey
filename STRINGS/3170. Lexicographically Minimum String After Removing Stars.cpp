//here i have solved using map
//but actually this question is of heap with comparator function

class Solution {
public:
    string clearStars(string s) {
        map<char,vector<int>>mp;
        string ans="";
        int index=0;
        for(int i =0;i<s.size();i++){
            if(s[i]!='*'){
                mp[s[i]].push_back(i);
            }
            else{
                for(auto &ele:mp){
                    if(ele.second.size()>0){
                        ele.second.pop_back();
                        break;
                    }
                }
            }
        }

        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='*')continue;
            auto &v=mp[s[i]];
            if(v.size()>0&&v.back()>=i){
               v.pop_back();
               ans+=s[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
