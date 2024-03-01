bool check(vector<int>&v,int &level){
   int n=v.size();
   if(level%2==0){ //EVEN LEVEL
       for(auto i:v) if(i%2==0) return false;
       for(int i=0;i<n-1;i++){
           if(v[i]>=v[i+1]) return false;
       }   
   }
   else{ //ODD LEVEL 
       for(auto i:v) if(i%2!=0) return false;
       for(int i=0;i<n-1;i++){
           if(v[i]<=v[i+1]) return false;
       } 
   }
   
   return true;

}
    bool isEvenOddTree(TreeNode* root) {
        if(root->val%2==0) return 0;
        if(root->left==NULL&&root->right==NULL&&root->val%2!=0) return true;

        int level=0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size()>0){
          int n=q.size();
          level++;
          vector<int>v;
          while(n--){
              auto front=q.front();
              q.pop();
              if(front->left){
                  q.push(front->left);
                  v.push_back(front->left->val);
                } 
               if(front->right){
                  q.push(front->right);
                  v.push_back(front->right->val);
                } 
            }
        if(!check(v,level)) return false;
        }
        return true;
    }
