 vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
       vector<int>ans;
       int m=rolls.size();
       int sum=0;
       for(auto i:rolls)sum+=i;
       int remainingSum=(mean*(n+m))-sum; 
       if(remainingSum>n*6 || remainingSum<n)return vector<int>();
       int remainder=remainingSum%n;
       int smallestElement=remainingSum/n;
       ans.resize(n,smallestElement);
       for(int i=0;i<remainder;i++){
        ans[i]++;
       }
       return ans;
    }
