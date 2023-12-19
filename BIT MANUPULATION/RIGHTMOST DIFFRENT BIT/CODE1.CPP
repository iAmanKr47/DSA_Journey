 int posOfRightMostDiffBit(int m, int n)
    {
        if(m==n)return -1;
        
        //if one number is odd and other is even then last bit would be diffrent for sure
        if( (m%2==0&&n%2!=0) ||(n%2==0&&m%2!=0)) return 1;   //THIS CONDITION IS NOT NECESSARY FOR THIS SOLTUION CZ ALONE WHILE LOOP CAN HANDLE ALL THE  CASES
        
       int cnt=1;
       while(m%2==n%2){
           cnt++;
           m/=2;n/=2;
       }
       return cnt;
        
    }
