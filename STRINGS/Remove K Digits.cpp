                                                        // STACK BASED APPROACH

string removeKdigits(string S, int k) {
        string ans=""; //act as a stack in this question
        for(auto ch:S){
            
            while(ans.size()>0 && k>0 && ans.back()>ch){
                ans.pop_back();
                k--;
            }
            ans+=ch;
        }
        // ans would contain elemnts in increasing order  a[0]<=a[1]<=a[2]<=.......<=a[n-1]. 
        // if k is not equalmto zero then 
        while(k--){
            ans.pop_back();
        }
        if(ans.size()==0) return "0";
        
        //removing trailing zeroes if any 
        int i=0;
        while(ans[i]=='0'){
            i++;
        }
        
        if(i==ans.size())return "0";
        
        return ans.substr(i);
        
    }
