//PROPERTY OF AND: bitwise AND of two different numbers will always be strictly less than the maximum of those two numbers OR  Bitwise AND results in a value that is always less than or equal to the operands
//THEREFORE MAXIMUM BITWISE AND VALUE OF THE ARRAY WOULD BE THE MAX VALUE OF THE ARRAY  
//THIS BOILS DOWN THE QUESION TO : FIND SUBARRAY HAVING MAX LENGTH CONTAINING MAX NUMBER OF THE ARRAY
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = 0, ans = 0, currentStreak = 0;

        for (int num : nums) {
            if (maxVal < num) {
                maxVal = num;
                ans = currentStreak = 0;
            }

            if (maxVal == num) {
                currentStreak++;
            } else {
                currentStreak = 0;
            }

            ans = max(ans, currentStreak);
        }
        return ans;
    }
};
