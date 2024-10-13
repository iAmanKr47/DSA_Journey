class Solution {
  public:
    bool isPalindrome(vector<int>&freq,int &k){
        int oddCnt=0;
        for(auto i:freq){
            if(i%2!=0)oddCnt++;
        }
       
        if(k%2!=0 && oddCnt==1)return true;
        if(k%2==0 && oddCnt==0)return true;
        return false;
    }
    int countPalindromicSubstrings(string str, int k) {
        // code here
        int n=str.size();
        if(k==1)return n;
        vector<int>freq(26,0);
        int ans=0;
        int l=0;
        int h=0;
        while(h<k){
            freq[str[h]-'a']++;
            h++;
        }
        if(isPalindrome(freq,k))ans++;
        while(h<n){
            freq[str[l]-'a']--;
            freq[str[h]-'a']++;
            if(isPalindrome(freq,k))ans++;
            l++;
            h++;
        }
        return ans;
    }
};
