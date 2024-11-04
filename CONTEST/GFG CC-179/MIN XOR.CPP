//BIT MANIPULATION

int minXOR(int n, int k, vector<int> &arr) {
       int ans=0;
       //start from MSB bit (left side)
       for(int i=30;i>=0;i--){
           int bitCnt=0;
           //check the i-th bit from each number
           for(int num:arr){
               if(num&(1<<i))bitCnt++;
           }
           //if set bit cnt is even then XOR val is zero 
           //else try to just flip the ith bit of any number which is set
           if(bitCnt%2!=0 ){
               if(k>0)k--;
               else ans|=(1<<i); //if k gets exhaust then just take the or value of that bit with ans 
           }
       }
       
       return ans;
    }
