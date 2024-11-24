//we can propagate negative sign in the whole matrix 
//if count of negative numbers are odd in the matrix then 1 negative number will be left over and to maximise the overall sum of the matrix we need that negative sign to be on the minimum number

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int minValue = INT_MAX;
        long long sum = 0;
        int negCount = 0;
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] < 0)
                    negCount++;
                int absValue = abs(matrix[i][j]);
                minValue = min(minValue, absValue);
                sum += absValue;
            }
        }
         
        if (negCount % 2 == 0)
            return sum;
        return sum - 2 * minValue;
    }
};
