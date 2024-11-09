//very important concept

long long minEnd(int n, int x) {
       long long ans=x;
       long long prev=x;
       long long i=x+1;
       int cnt=1;
       while(n--){
           //if current number is already giving x while doing (x&curr) then just add it to the count 
           if(x&i==x){
            x=x&i;
            prev=i;
            i++;
           }
             //else try to take (currNumber|x) ,this would be the next number that would give x when doing AND OPERATION with x ,i.e  x&(currNum|x) ==x 
             //it will give 
           else{
            prev=x|i;
            i=prev+1;
           }
           cnt++;
       }
       return prev;
     }
};
