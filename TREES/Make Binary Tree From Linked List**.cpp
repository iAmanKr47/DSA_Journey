//refer gfg question link to explore more solutions

void convert(Node *head, TreeNode *&root) {
    vector<int>arr;
    Node *temp=head;
    while(temp!=NULL){
        arr.push_back(temp->data);
        temp=temp->next;
    }
    int n=arr.size();
    root=new TreeNode(arr[0]);
    queue<pair<TreeNode*,int>>q;
    q.push({root,0});
   //build tree from given array elements
    while(q.size()>0){
        auto front=q.front();
        q.pop();
        auto currNode=front.first;
        int ind=front.second;
        int leftIndex=(2*ind)+1;
        int rightIndex=(2*ind)+2;
        
        if(leftIndex>=n)currNode->left=NULL;
        else{
            TreeNode* leftNode=new TreeNode(arr[leftIndex]);
            currNode->left=leftNode;
            q.push({leftNode,leftIndex});
        }
        if(rightIndex>=n)currNode->right=NULL;
        else{
            TreeNode* rightNode=new TreeNode(arr[rightIndex]);
            currNode->right=rightNode;
            q.push({rightNode,rightIndex});
        }
    }
}


//optimised approach

void convert(Node *head, TreeNode *&root) {
    Node *temp=head->next;
    queue<TreeNode*>q;
    root=new TreeNode(head->data);
    q.push(root);
    while(q.size()>0 && temp){
        auto front=q.front();
        q.pop();
        //left node of the front Node
        TreeNode *leftNode=new TreeNode(temp->data);
        q.push(leftNode);
        temp=temp->next;
        front->left=leftNode;
        
        //right node of the front node
        if(temp){//if temp is null then whole tree is constructed
        TreeNode *rightNode=new TreeNode(temp->data);
        q.push(rightNode);
        temp=temp->next;
        front->right=rightNode;
        } 
    }
    
