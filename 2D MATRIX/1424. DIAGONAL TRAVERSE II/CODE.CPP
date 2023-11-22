vector<int> findDiagonalOrder(vector<vector<int>>& nums) {

// STORED THE ELEMENTS OF THE MATRIX IN MAP w.r.t TO THE SUM OF THEIR INDEXES(i, j) 
        map<int, vector<int>> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < nums[i].size(); j++)
            {
                int x = i+j;
                mp[x].push_back(nums[i][j]);
            }
        }
// THEN STORING THE ELEMENTS IN THE ANS VECTOR IN THE REVERSE ORDER i.e. DESCENDING ORDER
        vector<int> ans;
        for(auto it: mp)
        {
            for(int i = it.second.size()-1; i >= 0; i--) ans.push_back(it.second[i]);
        }
        return ans;
    }
