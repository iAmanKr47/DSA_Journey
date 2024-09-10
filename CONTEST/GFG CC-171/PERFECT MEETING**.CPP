//RANGE BASED QUESTION : Start Time and End Time 

int firsthour(int n, vector<vector<int>> arr) {
        sort(arr.begin(),arr.end());
        int maxStart=arr[0][0];
        int minEnd=arr[0][1];
        for(int i=1;i<n;i++){
            int currStart=arr[i][0];
            int currEnd=arr[i][1];
            if(currStart>=maxStart && currStart<=minEnd){
                maxStart=max(maxStart,currStart);
                minEnd=min(minEnd,currEnd);
            }
            else return 0;
            
        }
        return 1;
    }
