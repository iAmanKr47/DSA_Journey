string customSortString(string order, string s) {
        string res;
        vector<int> cnt(26, 0);
        for(auto ch: s){
            cnt[ch-'a']++;
        }

        for(int i = 0; i < order.size(); i++){
            while(cnt[order[i] -'a']-- > 0){
                res += order[i];
            }
        }

        for(int i = 0; i < 26; i++){
            while(cnt[i]-- > 0){
                res += i + 'a';
            }
        }

        return res;
}



//Approach :2

 map<int,string>mp2;
        for(char c:s)
        {
            int ascii = c-'a';
            mp2[ascii] += c;
        }

        string ans;
        for(char c:order)
        {
            int ascii = c-'a';
            ans += mp2[ascii];
            mp2[ascii] = "";
        }
        for(auto x:mp2) ans += x.second;
        return ans;
}
