vector<vector<int>> findTriplets(vector<int> &arr) {
        // Code here
        vector<vector<int>>v;
        int n=arr.size();
        unordered_map<int,vector<pair<int,int>>>mp; //stores the sum and the pair of index corresponds to that sum
  //store sum of each pair
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int sum=arr[i]+arr[j];
                mp[sum].push_back({i,j});
            }
        }
  //now search for other two elemnts that can form triplet whose sum is zero
        for(int i=0;i<n;i++){
            if(mp.find(-arr[i])!=mp.end()){
                auto tempVec=mp[-arr[i]];
                for(auto p:tempVec){
                    if(p.first>i){
                        v.push_back({i,p.first,p.second});  
                    }
                }
            }
        }
        return v;
    }
