int posOfRightMostDiffBit(int m, int n)
    {
        if(m==n) return -1;
        int num = m^n;                  //XOR GIVES 0 XOR while comparing (0,0)or (1,1) and gives 1 while comparing  opposite (1,0)or(0,1)  
        int ans=1;
        while(num>0) {
            if(num&1) {
                return ans;
            }
            num = num>>1;
            ans++;
        }
        return ans;
    }
