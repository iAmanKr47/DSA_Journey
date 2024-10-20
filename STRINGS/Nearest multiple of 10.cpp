string roundToNearest(string str) {
        // Complete the function
        auto lastDig=str.back();
        int n=str.size();
        str[n-1]='0';
        if(lastDig=='0'||lastDig=='1' || lastDig=='2' || lastDig=='3' || lastDig=='4' || lastDig=='5') {
            return str;
        }
       
       int i=n-2;
       int carry=1;
       while(i>=0 && carry==1){
           char ch=str[i]-'0';
           int sum=ch+carry;
           int dig=sum%10;
           if(dig!=0){
             str[i]=sum +'0';
             return str;
           }
           str[i]='0';
           i--;
       }
       str='1'+str;
       return str;
    }
