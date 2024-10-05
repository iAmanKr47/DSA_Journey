//SLIDING WINDOW : FIXED WINDOW SIZE
// REFER MIK

bool checkInclusion(string s1, string s2) {
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);
        int n1=s1.size();
        int n2=s2.size();
        if(n2<n1)return false;
        for(auto i:s1)freq1[i-'a']++;
       
        int s=0;
        int e=0;
        //we have to maintain a fixed window of length equal to size of string s1
        while(e<n2 ){
            // currWindowSize=e-s+1;
            freq2[s2[e]-'a']++;
            if(e-s+1>n1){//shrinking phase
                   freq2[s2[s]-'a']--;
                   s++; 
            }
            if(freq1==freq2)return true;
            e++;
        }
        return false;
    }
