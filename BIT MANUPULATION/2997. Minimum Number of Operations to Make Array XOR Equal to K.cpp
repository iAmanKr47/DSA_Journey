//code 1 :
 int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        for (auto& x : nums) {
            ans = ans ^ x;
        }
        ans = ans ^ k;
        int res = 0;
        while (ans > 0) {
            if (ans & 1)
                res++;
            ans = ans >> 1;
        }
        return res;
    }

//code 2:

int minOperations(vector<int>& nums, int k) {
        for(int x: nums)
            k ^= x;
        return __builtin_popcount(k);
    }
