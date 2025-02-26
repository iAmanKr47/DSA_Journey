//KADANE'S ALGORITHM

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum=INT_MIN;
        int minSum=INT_MAX;
        int n=nums.size();
        int sum = 0;
      //FIND MAXSUM
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum > maxSum) maxSum = sum;
            if (sum < 0) sum = 0;
        }
      //FIND MINSUM
        sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum < minSum) minSum = sum;
            if (sum > 0) sum = 0;
        }

      //RETURN ABSOLUTE MAX VALUE OF BOTH THE SUM.
        return max(maxSum,abs(minSum));
    }
};
