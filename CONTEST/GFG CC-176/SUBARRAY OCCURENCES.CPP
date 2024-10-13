//STORE THE MAPPING OF NUMBER AND ITS INDEXES WHERE THEY OCCURED
//INDEXES ARE STORED IN MANNER
//NOW USE BINARY SEARCH:  TO GET THE COUNT OF NO. 'K' IN THE RANGE [L,R] 



class Solution {
  public:
    vector<int> countOccurrences(int n, int q, vector<int> &arr,vector<vector<int>> &queries) {
    unordered_map<int,vector<int>>mp; //no. and it's occurence index in the arr
    vector<int>ans;
    for(int i=0;i<n;i++){
        mp[arr[i]].push_back(i);
    }
    for(auto v:queries){
        int l=v[0];
        int r=v[1];
        int k=v[2];
        
        if(mp.find(k)!=mp.end()){
        auto vec=mp[k];
        auto lower = lower_bound(vec.begin(), vec.end(), l)-vec.begin();
        auto upper = upper_bound(vec.begin(), vec.end(), r)-vec.begin();
        if(upper-lower>0)ans.push_back(upper-lower);
        }
        else  ans.push_back(0);
    }
    return ans;
    }
    
};
