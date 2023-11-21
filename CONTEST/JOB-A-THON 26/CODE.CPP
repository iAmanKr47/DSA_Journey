int scoreOfArray(int n, vector<int> &arr) {
            //SLIDING WINDOW CONCEPT
  
            int minRight=INT_MAX;
            int minLeft=arr[0];
            int j;
            int maxScore=INT_MIN;
            //MINRIGHT FOR FIRST ELEMENT 
            for(int i=2;i<n;i++)
            minRight=min(minRight,arr[i]);
        
            for(int i=1;i<n-1;i++){
            //STEP 1 CALCUALTE SCORE FOR INDEX 
            maxScore=max(maxScore,max(arr[i]-minLeft,arr[i]-minRight));
              
            //STEP 2 MINLEFT UPDATION IF NEW MIN ELEMNT IS FOUND 
            if(arr[i]<minLeft) minLeft=arr[i];

            //STEP 3  MIN RIGHT UPDATION IF CURR ELEMNT IS THE MINIMUM
            if(minRight>arr[i]){
            j=i+1;
            while(j<n)
             minRight=min(minRight,arr[j++]);   
            }
        }
        return maxScore;
    }
