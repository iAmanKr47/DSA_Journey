class Solution {
public:
    bool isPossible(int n, int k, vector<int> &stalls,int &minDiff){
        int cowsPlaced=1; //one cow can be placed at the starting always
        int prevStallPos=stalls[0];//prevStall track the last stall where cowss were placed successfully
        for(int i=1;i<n;i++){
            if(stalls[i]-prevStallPos>=minDiff){
                cowsPlaced++;
                prevStallPos=stalls[i];
            }
            if(cowsPlaced>=k)return true;
        }
        return false;
    }
    int solve(int n, int k, vector<int> &stalls) {
      //range of diffrence would be b/w [1,maxelement]
      sort(stalls.begin(),stalls.end());
      int low=1;
      int high=stalls[n-1];
      while(low<=high){
          int mid=low+(high-low)/2;
          if(isPossible(n,k,stalls,mid)){
              low=mid+1;
          }
          else high=mid-1;
      }
      return high ;//reverse polarity: high would be pointing to the desireable.
    }
