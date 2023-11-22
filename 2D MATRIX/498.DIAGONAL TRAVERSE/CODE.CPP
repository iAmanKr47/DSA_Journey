 vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int ,vector<int>>mp;
        vector<int>ans;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }
        bool isreverse =true;
        for(auto i:mp){
            auto vec=i.second;
            if(isreverse) {reverse(vec.begin(),vec.end());
            isreverse=false;
            }
            else isreverse=true;
            for(auto ele:vec) ans.push_back(ele);
        }
        return ans;
    }
