void solve(Node* root, int &input,int &ceilVal){
    if(root==NULL){
        return;
    }
    if(root->data>=input){
        ceilVal=root->data;
        solve(root->left,input,ceilVal);
    }
    else
    solve(root->right,input,ceilVal);
    
}
