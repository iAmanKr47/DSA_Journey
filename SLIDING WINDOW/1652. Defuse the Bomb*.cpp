
class Solution {
public:
void solve1(vector<int>& code,vector<int>&ans,int &k){
          int e=k;
          int n=code.size();
          int sum=0;
          for(int i=0;i<=k;i++)sum+=code[i];
          for(int i=0;i<n;i++){
              sum-=code[i];
              ans[i]=sum;
              e=(e+1)%n;
              sum+=code[e];
          }
}
void solve2(vector<int>& code,vector<int>&ans,int &k){
          k=abs(k);
          int n=code.size();
          int s=n-k;
          int e=n-1;
          int sum=0;
          for(int i=s;i<=e;i++)sum+=code[i];
          for(int i=0;i<n;i++){
              ans[i]=sum;
              sum-=code[s];
              s=(s+1)%n;
              e=(e+1)%n;
              sum+=code[e];
          }
}
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int>ans(n,0);
        if(k==0)return ans;
        if(k>0){
            solve1(code,ans,k);
        }
        else solve2(code,ans,k);
        return ans;
        
    }
};


//more clean code
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> result(code.size(), 0);
        if (k == 0) return result;
        // Define the initial window and initial sum
        int start = 1, end = k, sum = 0;
        // If k < 0, the starting point will be end of the array.
        if (k < 0) {
            start = code.size() - abs(k);
            end = code.size() - 1;
        }
        for (int i = start; i <= end; i++) sum += code[i];
        // Scan through the code array as i moving to the right, update the
        // window sum.
        for (int i = 0; i < code.size(); i++) {
            result[i] = sum;
            sum -= code[start % code.size()];
            sum += code[(end + 1) % code.size()];
            start++;
            end++;
        }
        return result;
    }
};
