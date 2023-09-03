bool isIsomorphic(Node *r1,Node *r2)
    {
        if(r1==NULL&&r2==NULL)
        return true;
        
        if(r1==NULL||r2==NULL)
        return false;
        
        if(r1->data!=r2->data)
        return false;
        
        bool check1=isIsomorphic(r1->left,r2->left) && isIsomorphic(r1->right,r2->right);
        bool check2=isIsomorphic(r1->left,r2->right) && isIsomorphic(r1->right,r2->left);
        
        return check1 || check2;
    
        
    }
