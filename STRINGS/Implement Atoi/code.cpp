int atoi(string s) {
      
       int n=s.size();
       int i=n-1;
       int num=0;
       int placeValue=0;
       while(i>=0){
           if(s[i]>='0' && s[i]<='9'){
               int digi=s[i]-'0';
               num+=digi*pow(10,placeValue);
               placeValue++;
               
           }
           else if (i==0 && s[i]=='-') break;
           else return -1;
           i--;
       }
       if(s[0]=='-')num=(-1)*num;
       return num;
    }
