int pairWithMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        if (n < 2) return -1;
        
        int maxSum = INT_MIN;
        for (int i = 1; i < n; ++i) {
            maxSum = max(maxSum, arr[i] + arr[i - 1]);
        }
        
        return maxSum;
    }
