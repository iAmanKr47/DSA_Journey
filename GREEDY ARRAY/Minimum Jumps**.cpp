int minJumps(vector<int>& arr) {
        if(arr[0]==0)return -1;
        int n=arr.size();
        int currPos=0;
        int steps=0;
        while(currPos<n-1){
            if(arr[currPos]==0)return -1;
            if(arr[currPos]+currPos>=n-1)return steps+1;
            
            int stepsCanJump=arr[currPos];
            int maxNextJump=-1;
            int nextJumpIndex;
            
            int i=currPos+1;
            // choose that index in the range which would lead to the maximum right index of the array and this makes this question on greedy approach.
            while(stepsCanJump--){
                int currJump=i+arr[i];//important step*
                if(maxNextJump<=currJump){
                   nextJumpIndex=i;
                   maxNextJump=currJump;
                }
                i++;
            }
            steps++;
            currPos=nextJumpIndex;
        }
        return steps;
    }
