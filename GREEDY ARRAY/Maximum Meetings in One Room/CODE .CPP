vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
       
        // create pair of finish and meeting numberor(or index)
        // only thing to note is that one meeting will start only if one meeting is ended so that's why creating pair of finish time and sort according to it 
        
        vector<pair<int,int>>mp;
        
        for(int i=0;i<N;i++){
            mp.push_back({F[i],i});
        }
        sort(mp.begin(),mp.end());
        
        vector<int>ans;
        ans.push_back(mp[0].second+1); // always able to finish first meeting
        int finish=mp[0].first;
        
        for(int i=1;i<N;i++){
            if(S[mp[i].second]>finish){
                ans.push_back(mp[i].second+1);
                finish=mp[i].first;
            }
            
        }
         sort(ans.begin(),ans.end());
        return ans;
    }
