//use concept of number line 
//use bfs/dfs traversal
int verticalWidth(Node* root) {
        if(root==NULL)return 0;
        if( root->left==NULL&&root->right==NULL)return 1;
        //BFS TRAVERSAL
        int left=0;
        int right=0;
        
        queue<pair<Node*,int>>q;//store node and its x co-ordinate
        q.push({root,0});
        while(q.size()>0){
            auto front=q.front();
            q.pop();
            auto frontNode=front.first;
            int xAxis=front.second;
            
            if(frontNode->left){
                q.push({frontNode->left,xAxis-1});
                left=min(left,xAxis-1);
            }
            if(frontNode->right){
                q.push({frontNode->right,xAxis+1});
                right=max(right,xAxis+1);
            }
            
        }
        int ans= abs(left)+right+1;
        return ans;
    }
