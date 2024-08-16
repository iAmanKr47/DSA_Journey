//LEETCODE PREMIUM QUES
//https://leetcode.ca/all/624.html#:~:text=We%20define%20the%20distance%20between,5%20in%20the%20second%20array.
//https://github.com/doocs/leetcode/edit/main/solution/0600-0699/0624.Maximum%20Distance%20in%20Arrays/README_EN.md

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int ans = 0;
        int mini = arrays[0][0], maxi = arrays[0][arrays[0].size() - 1]; //global maxi and mini
        for (int i = 1; i < arrays.size(); ++i) {
            auto& arr = arrays[i];
            int currMin=arr[0]; //min elemnt of curr array
            int currMax=arr[arr.size() - 1]; // max elemnt of curr array
            int diff1 = abs(currMin - maxi), diff2 = abs(currMin- mini);
          
            ans = max({ans,diff1,diff2});
           //update global minimum and global maximum
            mini = min(mini,currMin);
            maxi = max(maxi, currMaxi);
        }
        return ans;
    }
};
