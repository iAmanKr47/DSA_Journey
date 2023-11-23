vector<long long> nthRowOfPascalTriangle(int n) {
       
        vector<long long> prevRow;
        
        for (int i = 0; i < n; i++) {
            vector<long long> currentRow(i + 1, 1);
            for (int j = 1; j < i; j++) {
                currentRow[j] = (prevRow[j - 1] + prevRow[j])%1000000007 ;
            }
            prevRow = currentRow;
        }

        return prevRow ;
    }
