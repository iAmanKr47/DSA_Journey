// Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        // code here...
         int currSum=0;
        int max=INT_MIN;
        for(int i=0;i<arr.size();i++)
        {
            currSum=currSum+arr[i];
            if(currSum>max)
            {
                max=currSum;
            }
            if(currSum<0)
            {
                currSum=0;
            }
        }
       return max;
    }
