//PREFIX-SUM(Sliding window) + RECURSION
//T.L.E
class Solution {
public:
    int first=-1;
    int second=-1;
    int third=-1;
    vector<int>ans;
    long long maxSum=0;
    void solve(vector<long long>& suffixSum, int &k,int currIndex, int cnt){
         if(cnt>=3){
            long long sum=suffixSum[first]+suffixSum[second]+suffixSum[third];
            if(sum>maxSum){
              ans.clear();
              ans.push_back(first);
              ans.push_back(second);
              ans.push_back(third);
              maxSum=sum;
            }
            return;
         }
         if(currIndex>=suffixSum.size())return;
         
         if(cnt==0){
            first=currIndex;
         }
         else if(cnt==1)second=currIndex;
         else third=currIndex;


         solve(suffixSum,k,currIndex+k,cnt+1);
         solve(suffixSum,k,currIndex+1,cnt);
         
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        //every index would store sum from currentIndex to (currentIndex + k)
        vector<long long>suffixSum(n,0);
        int s=0;
        int e=0;
        long long currSum=0;
        while(e<k){
            currSum+=nums[e++];
        }
        suffixSum[s]=currSum;
        while(e<n){
          currSum-=nums[s++];
          currSum+=nums[e++];
          suffixSum[s]=currSum;
        }
        solve(suffixSum,k,0,0);
        return ans;
    }
};
