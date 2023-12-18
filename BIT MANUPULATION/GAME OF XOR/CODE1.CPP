int gameOfXor(int n, int a[]) {
    int ans = 0;
    
    // If the size of the array is even, the result is 0.
    if (n % 2 == 0)
        return 0;
    
    // Loop through each element of the array.
    for (int i = 0; i < n; i++) {
        // Calculate the count of subarrays in which the current element participates.
        int count = (n - i) * (i + 1);
        
        // If the count is odd, update the result using XOR with the current element.
        if (count % 2)
            ans = ans ^ a[i];
    }
    
    // Return the final result.
    return ans;
}

