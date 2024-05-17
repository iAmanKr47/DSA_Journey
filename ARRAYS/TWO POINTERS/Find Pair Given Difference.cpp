//use two pointer appraoch : but instead of pointing left pointer to first index and right pointr to last index,
//Two pointers, left and right, are initialized at indices 0 and 1 respectively.

 int findPair(int n, int x, vector<int> &arr) {
        sort(arr.begin(), arr.end());
        int left = 0;
        int right = 1;
        while(left < n && right < n)
        {
            int temp = (arr[right]-arr[left]);
            if(temp == x && left != right)  return 1;
            else if(temp > x) left++;
            else right++;                // if(left==right)  right++;
        }
        return -1;
    }
