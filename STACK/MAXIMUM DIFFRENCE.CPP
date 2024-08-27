//STACK BASED APPRAOCH
T.C: O(N)
S.C: O(N)+O(N)+O(N)    //STACK+LEFTARRAY+RIGHTARRAY


    int findMaxDiff(vector<int> &arr) {
        // Your code here
        stack<int>st;
        int n=arr.size();
        int maxi=INT_MIN;
        vector<int>leftArray(n,0);
        vector<int>rightArray(n,0);
        //leftSmaller elements are ready
        for(int i=0;i<n;i++){
            int curr=arr[i];
            while(st.size() && st.top()>=curr)st.pop();
            if(st.size()>0){
                leftArray[i]=st.top();
            }
            st.push(curr);
        }
        
        // Clearing all elements from the stack
        // By assigning new empty stack
        st= stack<int>();
        
        //RightSmaller elements are ready
        for(int i=n-1;i>=0;i--){
            int curr=arr[i];
            while(st.size() && st.top()>=curr)st.pop();
            if(st.size()>0){
                rightArray[i]=st.top();
            }
            st.push(curr);
        }
        for(int i=0;i<n;i++){
            maxi=max(maxi,abs(leftArray[i]-rightArray[i]));
        }
        return maxi;
    }



//CODE 2 : SAME LOGIC AS ABOVE JUST RIGHT ARRAY IS NOT USED
T.C: O(N)
S.C: O(N)+O(N)
          
int findMaxDiff(vector<int> &arr) {
        // Your code here
        stack<int>st;
        int n=arr.size();
        int maxi=INT_MIN;
        vector<int>leftSmaller(n,0);
        //leftSmaller elements are ready
        for(int i=0;i<n;i++){
            int curr=arr[i];
            while(st.size() && st.top()>=curr)st.pop();
            if(st.size()>0){
                leftSmaller[i]=st.top();
            }
            st.push(curr);
        }
        
        // Clearing all elements from the stack
        // By assigning new empty stack
        st= stack<int>();
        
        //RightSmaller elements are ready
        for(int i=n-1;i>=0;i--){
            int curr=arr[i];
            while(st.size() && st.top()>=curr)st.pop();
            
            int rightSmaller=st.size()>0?st.top():0;
            maxi=max(maxi,abs(leftSmaller[i]-rightSmaller));
            
            st.push(curr);
        }
        return maxi;
    }
