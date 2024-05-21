//LCM FIND OUT 
class Solution {
  public:
    long long firstContact(int n, int m) {
        
        int maxi=max(n,m);
        int mini=min(n,m);
        long long sum=maxi;
        while(true){
            if(sum%mini==0)return sum;
            sum+=maxi;
        }
        return sum;
    }
};

