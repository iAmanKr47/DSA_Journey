class Solution{
    public:
    void inOrder(Node* root, vector<int> &inOrderValue) {
    if(root == NULL)
        return;
    inOrder(root -> left, inOrderValue);
    inOrderValue.push_back(root -> data);
    inOrder(root -> right, inOrderValue);
}
Node* inOrderToBST(int start, int end, vector<int> &inOrderValue) {
    if(start > end)
        return NULL;
    int mid = start + (end - start) / 2;
    Node* root = new Node(inOrderValue[mid]);
    root -> left = inOrderToBST(start, mid - 1, inOrderValue);
    root -> right = inOrderToBST(mid + 1, end, inOrderValue);
    return root;
}
Node* buildBalancedTree(Node* root)
{
	// Code here
	vector<int> inOrderValue;
  inOrder(root, inOrderValue);
  return inOrderToBST(0, inOrderValue.size() - 1, inOrderValue);
}
};
