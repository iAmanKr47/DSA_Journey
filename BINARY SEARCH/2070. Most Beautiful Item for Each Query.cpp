// BINARY SEARCH (UPPER BOUND ) + PREFIXSUM

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        int n=items.size();
        int m=queries.size();
        vector<int>result(m);
        vector<int>price(n);
        vector<int>maxPrefixBeauty(n);//stores the max beauty till that particular index
        for(int i=0;i<n;i++){
            price[i]=items[i][0];
            if(i-1>=0)maxPrefixBeauty[i]=max(maxPrefixBeauty[i-1],items[i][1]);
            else maxPrefixBeauty[i]=items[i][1];
        }
        for(int i=0;i<m;i++){
            auto index=upper_bound(price.begin(), price.end(), queries[i])-price.begin();
            if (index == 0) 
            result[i] = 0; // No item within the price range of queries[i]
            else 
            result[i] = maxPrefixBeauty[index - 1];
            
        }
        return result;
    }
};



//more clean 

class Solution {
public:
    static vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end()); // Sort items by price
        const int n = items.size(), m = queries.size();

        vector<int> mostBeauty(n);
        mostBeauty[0] = items[0][1];

        // Build up the mostBeauty array
        for (int i = 1; i < n; i++)
            mostBeauty[i] = max(mostBeauty[i-1], items[i][1]);

        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            int query = queries[i];
            vector<int>&& target={query, INT_MAX};
            // Use upper_bound to find the first item with a price > query
            int j = upper_bound(items.begin(), items.end(), target)-items.begin();
            // If j is 0, no items have price <= query
            if (j == 0) ans[i] = 0;
            else ans[i] = mostBeauty[j - 1];
        }

        return ans;
    }
};
