/*
PREFIX SUM APPROACH
S.C. : O(2^5)=O(32)
T.C. : O(N)
*/
class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> freqOfVowel(5, 0); // stores in order a e i o u // even occ:0 dd occ:1
        unordered_map<string, int> firstOcc; 
        int maxlen = 0;
        firstOcc["00000"] = -1;
        for (int i = 0; i < s.size(); i++) {
            if(s[i]=='a'){
                freqOfVowel[0]=(freqOfVowel[0]+1)%2;
            }
            else if(s[i]=='e'){
                freqOfVowel[1]=(freqOfVowel[1]+1)%2;
            }
            else if(s[i]=='i'){
                freqOfVowel[2]=(freqOfVowel[2]+1)%2;
            }
            else if(s[i]=='o'){
                freqOfVowel[3]=(freqOfVowel[3]+1)%2;
            }
            else if(s[i]=='u'){
                freqOfVowel[4]=(freqOfVowel[4]+1)%2;
            }
            string currState="";
            for(int i=0;i<5;i++){
                currState+=('0'+freqOfVowel[i]);
            }
            if(firstOcc.find(currState)!=firstOcc.end()){
                maxlen=max(maxlen,i-firstOcc[currState]);
            }
            else firstOcc[currState]=i;
        }
        return maxlen;
    }
};



//BIT MANIPULATION


int findTheLongestSubstring(string s) {
        vector<int> freqOfVowel(5, 0); // stores in order a e i o u // even occ:0 dd occ:1
        unordered_map<string, int> firstOcc;
        int maxlen = 0;
        firstOcc["00000"] = -1;
        for (int i = 0; i < s.size(); i++) {
            if(s[i]=='a'){
                freqOfVowel[0]=(freqOfVowel[0]^1);
            }
            else if(s[i]=='e'){
                freqOfVowel[1]=(freqOfVowel[1]^1);
            }
            else if(s[i]=='i'){
                freqOfVowel[2]=(freqOfVowel[2]^1);
            }
            else if(s[i]=='o'){
                freqOfVowel[3]=(freqOfVowel[3]^1);
            }
            else if(s[i]=='u'){
                freqOfVowel[4]=(freqOfVowel[4]^1);
            }
            string currState="";
            for(int i=0;i<5;i++){
                currState+=('0'+freqOfVowel[i]);
            }
            if(firstOcc.find(currState)!=firstOcc.end()){
                maxlen=max(maxlen,i-firstOcc[currState]);
            }
            else firstOcc[currState]=i;
        }
        return maxlen;
    }




//BIT MANIPULATION BETTER AND CLEAN CODE


 int findTheLongestSubstring(string s) {
       
        unordered_map<int, int> firstOcc;
        int maxlen = 0;
        int mask=0;
        firstOcc[mask] = -1;
        for (int i = 0; i < s.size(); i++) {
            if(s[i]=='a'){
                mask=mask^(1<<0);
            }
            else if(s[i]=='e'){
                mask=mask^(1<<1);
            }
            else if(s[i]=='i'){
                mask=mask^(1<<2);
            }
            else if(s[i]=='o'){
               mask=mask^(1<<3);
            }
            else if(s[i]=='u'){
                mask=mask^(1<<4);
            }
            
            if(firstOcc.find(mask)!=firstOcc.end()){
                maxlen=max(maxlen,i-firstOcc[mask]);
            }
            else firstOcc[mask]=i;
        }
        return maxlen;
    }
