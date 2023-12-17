                                                        //TLE SOLUTION 
                                                       //CAN BE OPTIMISED THROUGH DP

void solve(int* arr, int &n,int index, int& currentSum) {
    // Base case: If we reach the end of the array
    if (index >= n) {
        return;
    }

    // Recursive case: Two possibilities - include the current element or exclude it
    // If the current element is included, skip the next element
    int includeCurrent = currentSum + arr[index];
    solve(arr, n,index + 2, includeCurrent);

    // If the current element is excluded, move to the next element
    int excludeCurrent = currentSum;
    solve(arr, n,index + 1, excludeCurrent);

    // Update the currentSum with the maximum of including or excluding the current element
    currentSum = max(includeCurrent, excludeCurrent);
} 
//calculate the maximum sum with out adjacent
	
	int findMaxSum(int *arr, int n) {
	    int currentSum=0;
	    solve(arr,n,0,currentSum);
	    return currentSum;
	}
