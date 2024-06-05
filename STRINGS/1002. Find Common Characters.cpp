vector<string> commonChars(vector<string>& words) {
        int n=words.size();
        vector<string>ans;
        vector<vector<int>>freq(n,vector<int>(26,0));//craete 2d vector of size (n x 26) store the freq of all character of each word
        for(int i=0;i<n;i++){
            auto word=words[i];
            for(auto ch:word)freq[i][ch-'a']++;
        }
        //now find the minimum freq of  each character and include that in your ans
        for(int j=0;j<26;j++){
            int miniOccurence=freq[0][j];
            for(int i=0;i<n;i++){
                miniOccurence=min(miniOccurence,freq[i][j]);
            }
            //store ch in ans , min occurence times 
            while(miniOccurence--){
                    string ch="";
                    ch+=j+'a';
                    ans.push_back(ch);
            }
        }
        return ans;
    }
