//this is brute force solution use DP to optimise the approach 
//code 1
class Solution {
  public:
  int maxiCnt=1;
    void solve(vector<int>&a,int index,vector<int>&temp){
        if(index>=a.size()){
            int size=temp.size();
            maxiCnt=max(maxiCnt,size);
            return ;
        }
        if(temp.size()==0 || abs(temp.back()-a[index])==1 ){
            temp.push_back(a[index]);
            solve(a,index+1,temp);
            temp.pop_back();
            solve(a,index+1,temp);
        }
        else{
        solve(a,index+1,temp);
            
        }
        
    }
    int longestSubseq(int n, vector<int> &a) {
        vector<int>temp;
        solve(a,0,temp);
        return maxiCnt;
    }
};


//code 2:

class Solution {
  public:
  int maxiCnt=1;
    void solve(vector<int>&a,int index,vector<int>&temp){
        if(index>=a.size()){
            int size=temp.size();
            maxiCnt=max(maxiCnt,size);
            return ;
        }
        solve(a,index+1,temp);
        if(temp.size()==0 || abs(temp.back()-a[index])==1 ){
            temp.push_back(a[index]);
            solve(a,index+1,temp);
            temp.pop_back();
        }
        
        
    }
    int longestSubseq(int n, vector<int> &a) {
        vector<int>temp;
        solve(a,0,temp);
        return maxiCnt;
    }
};
