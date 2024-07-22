

class Solution {
public:
    // Function to return a list of integers denoting the
    // node values of both the BST in a sorted order.

    vector<int> arr1, arr2;

    void dfs(Node* root, bool which)
    {
        if (!root) {
            return;
        }
        dfs(root->left, which);
        if (!which) {
            arr1.push_back(root->data);
        }
        else {
            arr2.push_back(root->data);
        }
        dfs(root->right, which);
    }

    vector<int> merge(Node* root1, Node* root2)
    {
        dfs(root1, 0);
        dfs(root2, 1);
        vector<int> ans;
        int i = 0, j = 0;
        while (i < arr1.size() && j < arr2.size()) {
            if (arr1[i] > arr2[j]) {
                ans.push_back(arr2[j++]);
            }
            else {
                ans.push_back(arr1[i++]);
            }
        }
        while (i < arr1.size()) {
            ans.push_back(arr1[i++]);
        }
        while (j < arr2.size()) {
            ans.push_back(arr2[j++]);
        }
        return ans;
    }
};
