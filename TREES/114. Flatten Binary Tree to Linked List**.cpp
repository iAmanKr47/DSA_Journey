//Same as Flatten BST to sorted list: https://www.geeksforgeeks.org/problems/flatten-bst-to-sorted-list--111950/0

TreeNode* solve(TreeNode* root){
        if(root==NULL)return NULL;
        TreeNode*leftHead=solve(root->left);
        TreeNode*rightHead=solve(root->right);
        root->left=NULL;
        
        if(leftHead==NULL){ //IF NOTHING EXIST AT LEFT ATTACH RIGHT LL TO THE ROOT
            root->right=rightHead;
        }
        else{//FINDING TAIL
            TreeNode*tail=leftHead;
            while(tail && tail->right){
              tail=tail->right;
            }
            tail->right=rightHead; //FIRST ATTACH TAIL TO RIGHT LL //NOW LEFT AND RIGHT ARE COMBINED HAVING HEAD AS LEFTHEAD
            root->right=leftHead;  //NOW ATTACH THE COMBINED LL TO THE ROOT
        }
        return root; //RETURN ROOT AS IT'S THE HEAD OF THE NEW LINKEDLIST FORMED 

    }
    void flatten(TreeNode* root) {
        if(root==NULL)return ;
        solve(root);
    }
