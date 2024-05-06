vector<int> reverseLevelOrder(Node *root)
{
    queue<Node*>q;
    vector<int>ans;
    q.push(root);
    while(!q.empty()){
            auto front=q.front();
            q.pop();
            ans.push_back(front->data);
            if(front->right)q.push(front->right);
            if(front->left)q.push(front->left);
        
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
