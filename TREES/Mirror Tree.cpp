//DFS POST ORDER TRAVERSAL
class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        if (node == NULL) return;

        // calling mirror function recursively for left and right subtrees.
        mirror(node->left);
        mirror(node->right);

        // swapping the left and right subtree.
        swap(node->left, node->right);
    }
};


//BFS LEVEL ORDER TRAVERSAL

 void mirror(Node* node) {
        // code here
        if (node == nullptr)return;
    
        queue<Node*> q;
        q.push(node);
        // Perform BFS, swapping left and right children at each node
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            // Swap left child with right child
            swap(curr->left, curr->right);
    
            // Push left and right children to the queue
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    
    }
