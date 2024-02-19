int collectingCoins(int N, vector<vector<int>> &coins) {
        unordered_map<int ,int>mp1;// for same row
        unordered_map<int ,int>mp2;//for same column
        unordered_map<int ,int>mp3;// for same main diagonal
        unordered_map<int ,int>mp4;// for same secondary diagonal
        int maxCoins=0;
        for(auto v:coins) {
            mp1[v[0]]++;
            maxCoins=max(maxCoins,mp1[v[0]]);
        }
        
        for(auto v:coins) {
            mp2[v[1]]++;
            maxCoins=max(maxCoins,mp2[v[1]]);
        }
        for(auto v:coins) {
            mp3[v[0]-v[1]]++;
            maxCoins=max(maxCoins,mp3[v[0]-v[1]]);
        }
        for(auto v:coins) {
            mp4[v[0]+v[1]]++;
            maxCoins=max(maxCoins,mp4[v[0]+v[1]]);
        }
        return maxCoins
