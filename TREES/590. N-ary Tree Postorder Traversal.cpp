//logic used : see given example in question and analyse
/*
print the rootnode 
 move from right most child to leftmost child of the rootnode
first discover the subtree from rightmost child then  move to left side child and discover that subtree 
do so untill all the children gets visited
*/

//CODE : RECURSIVE

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int>ans;
    void solve(Node* root){
        if(root==NULL)return ;
        ans.push_back(root->val);
        auto vec=root->children;
        int n=vec.size();
        for(int i=n-1;i>=0;i--){ //discover the children nodes from the rightmost child thats why started the loop from last.
            solve(vec[i]); 
        }
    }
    vector<int> postorder(Node* root) {
        solve(root);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
