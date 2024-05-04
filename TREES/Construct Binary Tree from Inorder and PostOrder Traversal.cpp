#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}
node * constructTree(vector < int > & postorder, int postStart, int postEnd, 
vector < int > & inorder, int inStart, int inEnd, map < int, int > & mp) {
  if (postStart > postEnd || inStart > inEnd) return NULL;

  node * root = newNode(postorder[postEnd]);
  int elem = mp[root -> data];
  int nElem = elem - inStart;

  root -> left = constructTree(postorder, postStart, postStart + nElem - 1, 
  inorder, inStart, elem - 1, mp);
  root -> right = constructTree(postorder, postStart + nElem, postEnd-1, inorder,
  elem + 1, inEnd, mp);

  return root;
}

node * buildTree(vector < int > & postorder, vector < int > & inorder) {
  int postStart = 0, postEnd = postorder.size() - 1;
  int inStart = 0, inEnd = inorder.size() - 1;

  map < int, int > mp;
  for (int i = inStart; i <= inEnd; i++) {
    mp[inorder[i]] = i;
  }

  return constructTree(postorder, postStart, postEnd, inorder, inStart, inEnd, mp);
}

int main() {

  vector<int> postorder{40,50,20,60,30,10};
  vector<int> inorder{40,20,50,10,60,30};
  node * root = buildTree(postorder, inorder);
  return 0;
}



//code 2

class Solution
{
    public:

    //Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int in[], int post[], int n) {
         if (n==0) return NULL;
        Node *root=new Node(post[n-1]);
        if (n==1) return root;
        int i=0;
        for(i=0;i<n;i++){
            if(in[i]==post[n-1]) break;
        }
        
        root->left=buildTree(in,post,i);
        root->right=buildTree(in+i+1,post+i,n-i-1);
        return root;
    }
};
