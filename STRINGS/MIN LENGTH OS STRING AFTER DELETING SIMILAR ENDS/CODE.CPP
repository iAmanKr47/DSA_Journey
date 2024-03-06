int minimumLength(string s) {
        int n=s.size();
        if(n==1) return 1;
        int l=0;
        int h=n-1;
        while(l<=h){
           if(s[l]!=s[h]) return h-l+1; //CONDITION 4
           if(l==h) return 1; //HINT 2
           
           char ch=s[l];
           // PERFORM REMOVAL FROM BOTH END(PREFIX AND SUFFIX) ONE BY ONE 
           while(s[l]==ch && s[h]==ch){
               l++;
               h--;
           }
           //ONLY OF THE BELOW  WHILE LOOP WILL RUN IN EACH CASE
           //IF PREFIX PART HAS GREATER NUMBER OF SAME CHARACTER
           while(l<h &&s[l]==ch) l++;
           //IF RIGHT PART HAS GREATER NUMBER OF SAME CHARACTER
           while(h>l && s[h]==ch) h--;
        }
        return 0;
    }
