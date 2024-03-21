vector <int> diagonalSum(Node* root) {
        if( !root->left && !root->right) return {root->data};
        vector<int>ans;
        queue<pair<int,Node*>>q;  //to store the nodes with diagonal levels
        
            // to store the sum at each diagonal level
        map<int,int>mp;
        q.push(make_pair(0,root));
        
        while(q.size()>0){
            auto front=q.front();
            q.pop();
            mp[front.first]+=front.second->data;
            if(front.second->right) q.push(make_pair(front.first,front.second->right));
            if(front.second->left)  q.push(make_pair(1+front.first,front.second->left));
        }
        for(auto i:mp) ans.push_back(i.second);
        return ans;
    }
