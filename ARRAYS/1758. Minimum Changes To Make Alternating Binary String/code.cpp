//IDEA IS SIMPLE :THERE IS ONLY TWO ALTERNATE STRING POSSIBLE ONE WHICH START WITH 0 HAVING PATTTERN 010101.... OR WHICH START WITH 1 HAVING PATTERN 101010.....
//JUST CALCULATE MIS MATCH CHARACTER IN ALTERNATE STRING AND GIVEN STRING FOR BOTH ALTRENATE STRING 
//ANS WOULD BE MIN OF BOTH CASES

                                                        //APPRAOCH 1

int minOperations(string s) {
        int cnt=0;
        int n=s.size();
        //compare with that alternate pattern which starts with 0 i,e 01010101... 
        for(int i=0;i<s.size();i++)
        {
            //at even index it should be zero acc to our pattern 
         if(i%2==0) {
             //if there is a mismatch in character in pattern and in string S 
             if(s[i]=='1') cnt++;
         }
         //at odd index 
         else {
             if(s[i]=='0') cnt++;
         }
        }
        return min(cnt,n-cnt); //n-cnt is for comparing alternate pattern which starts with 1.
    }

//SIMPLIFIED CODE

int minOperations(string s) {
        int countForAlternate0 = 0;
        int countForAlternate1 = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (i % 2 == 0) {
                if (s[i] == '0') {
                    countForAlternate1++;
                } else {
                    countForAlternate0++;
                }
            } else {
                if (s[i] == '1') {
                    countForAlternate1++;
                } else {
                    countForAlternate0++;
                }
            }
        }
        
        return min(countForAlternate0, countForAlternate1);
    }
