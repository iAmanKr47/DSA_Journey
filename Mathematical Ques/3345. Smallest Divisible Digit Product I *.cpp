//need to check just 10 numbers as 0 is divisible by every number.

 int smallestNumber(int n, int t) {
        string num=to_string(n);
        int product=1;
        for(int i=n;i<n+10;i++){
            int product=1;
            int num=i;
            while(num>0){
                product*=num%10;
                num/=10;
            }
            if(product%t==0)return i;
        }
        return -1;
    }
