
class Solution
{
    public:
    long long  mod=1e9+7;
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        
       long long ans=0;
       int i=0;
       long long prev=0;
       long long curr;
       
       while(s[i]=='0')i++;// for trailing zeroes;
       
       for(int k=i;k<s.size();k++){
           curr=(prev*10+((k+1)*(s[k]-'0'))%mod)%mod;
           ans+=curr;
           prev=curr;
           
       }
       return ans%mod;
    }
};
