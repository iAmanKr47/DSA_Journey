APPROACH 1:
      
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


APPROACH 2:

int atoi(string s) {
        //Your code here
        int ans = 0;
        int sign = 1;
        
        for(int i = 0; i < s.size(); i++) {
            int ch = s[i];
            if(i == 0 && ch == '-') sign = -1;
            else if(ch >= '0' && ch <= '9') {
                int digit = ch - '0';
                ans = ans*10 + digit;
            }
            else {
                return -1;
            }
        }
        
        return sign*ans;
    
    }
