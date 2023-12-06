class Solution
{
public:
unordered_map<int,int>exist;
int cnt=0;
void mark(Node*root){
    if(root==NULL)
    return;
    exist[root->data]=1;
    mark(root->left);
    mark(root->right);
}

void search(Node* root,int &x){
    if(root==NULL)
    return;
    
    if(exist.find(x-root->data)!=exist.end())
    cnt++;
    search(root->left,x);
    search(root->right,x);
    
    
}
    int countPairs(Node* root1, Node* root2, int x)
    {
    mark(root1);
    search(root2,x);
    return cnt;
    }
};
