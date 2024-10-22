//BFS + MIN HEAP

long long kthLargestLevelSum(TreeNode* root, int k) {
        
        priority_queue<long long ,vector<long long >,greater<long long >>pq;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()>0){
            int size=q.size();
            long long currLevelSum=0;
            while(size--){
                auto front=q.front();
                q.pop();
                if(front->left)q.push(front->left);
                if(front->right)q.push(front->right);
                currLevelSum+=front->val;
            }
            if(pq.size()<k)pq.push(currLevelSum);
            else if(pq.top()<currLevelSum){
                pq.pop();
                pq.push(currLevelSum);
            }
        }
        if(pq.size()<k)return -1;
        return pq.top();
    }
