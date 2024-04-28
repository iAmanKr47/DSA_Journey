/* PROBLEM STATEMENT: 
     A restaurant has n ice creams. Each ice cream has some flavour represented by aj.
Geek and Geekina want to pick ice creams of the same flavor, but they want them to be atleast k inidices apart from each other i.e. If i and jare the indices of ice creams picked by Geek and Geekina respectively then |ij| >= k must hold.
Find the number of different ways they can order the ice creams.
Note: Return the number of different pairs such that a[i] = a[j] and | i-j| >=k. {i, j} and {j, i} count as the same pair.
*/


 long long findGoodPairs(vector<int> a, int n, int k) {
        long long ans=0;
        unordered_map<int,int>mp;
        int s=0;
        int e=k;
        while(e<n){
            mp[a[s]]++;
            ans+=mp[a[e]];
            s++;
            e++;
        }
        return ans;
    }
