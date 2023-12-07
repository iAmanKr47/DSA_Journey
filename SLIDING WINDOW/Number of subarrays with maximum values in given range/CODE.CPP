long countSubarrays(int a[], int n, int L, int R)
{
    // Complete the function
    // Two-Pointer 

    // Initialize variables
    long long start = -1;
    long long end = -1;
    long long count = 0;

    // Iterate through the array
    for (int i = 0; i < n; i++)
    {
        // If the current element is greater than R
        if (a[i] > R)
        {
            // Reset the start and end pointers to the current index
            start = i;
            end = i;
            continue; // Move to the next iteration
        }

        // If the current element is greater than or equal to L
        if (a[i] >= L)
        {
            // Update the end pointer to the current index
            end = i;
        }

        // Update the count by adding the difference between end and start pointers
        count += (end - start);
    }

    // Return the final count
    return count;
}
