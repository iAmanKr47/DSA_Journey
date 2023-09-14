void inorder(Node* root,vector<int> &v){

        if(root == NULL) return;

        inorder(root->left,v);

        v.push_back(root->data);

        inorder(root->right,v);

        

        

    }

    void fillPost(int &i,Node* root,vector<int> &in){

        if(root == NULL) return;

        fillPost(i,root->left,in);

        fillPost(i,root->right,in);

        root->data = in[i++];
    }

    void convertToMaxHeapUtil(Node* root)

    {
        if(root == NULL) return ;

        vector<int> ans;

        inorder(root,ans);

        int i=0;

        fillPost(i,root,ans);
    }    
