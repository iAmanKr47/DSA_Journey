
void pushZerosToEnd(vector<int>& arr) {
        int  n = arr.size();
        int index=0
        // Traverse the array. If element encountered is non-
        // zero, then replace the element at index 'index'
        // with this element
        for (int i = 0; i < n; i++)
            if (arr[i] != 0)
                arr[index] = arr[i];

        // Now all non-zero elements have been shifted to
        // front and 'index' is set as index of first 0.
        // Make all elements 0 from index to end.
        for(int i=index;i<n;i++) arr[i]=0;
    }
