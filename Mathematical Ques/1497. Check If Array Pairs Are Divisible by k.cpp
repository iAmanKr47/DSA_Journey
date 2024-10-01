//how to store reamainder of both positive number and neagtive number under single expression
//
bool canArrange(vector<int>& arr, int k) {
         vector<int> remainderFreq(k, 0);
        
        // Calculate remainder frequencies
        for (auto i : arr) {
            // Normalize the remainder for both positive and negative numbers
            int rem = (i % k + k) % k;
            remainderFreq[rem]++;
        }

        // Special case: remainder 0 should appear an even number of times
        if (remainderFreq[0] % 2 != 0) return false;
        
        // Check if remainder i and k-i can pair
        for (int i = 1; i <= k / 2; ++i) {
                if (remainderFreq[i] != remainderFreq[k - i]) return false;
        }
        
        return true;
    }
