//https://www.youtube.com/watch?v=bfKwLi6jtDk

class Solution {
public:
vector<vector<int>>ans;
    void solve(vector<int>& candidates, int index,int &target,int targetSum, vector<int>&temp){
         if(targetSum==target){
            ans.push_back(temp);
            return;
        }
        if(index>=candidates.size()|| targetSum>target)return;
       
       for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1])continue;
       temp.push_back(candidates[i]);
       solve(candidates,i+1,target,targetSum+candidates[i],temp);
       temp.pop_back();
        }   
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        solve(candidates,0,target,0,temp);
        
        return ans;

    }
};
