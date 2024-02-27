class Solution {
public:
int maxDia=0;
    int height(TreeNode* root){ //this function return the height of the tree just have done some modfication in the code of (height of tree) and we can compute this question      
        if(!root) return 0;

        int left=height(root->left);
        int right=height(root->right);
        maxDia=max(maxDia,left+right); //calculate max diameter at each node by assuming that node as root node
        return max(left,right)+1;

    }
    int diameterOfBinaryTree(TreeNode* root) {
        int h=height(root);
        return maxDia;

    }
};
