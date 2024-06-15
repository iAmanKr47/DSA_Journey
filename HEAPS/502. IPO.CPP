
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>vec;//pair of capital and profit
        int n=profits.size();
        for(int i=0;i<n;i++){
            vec.push_back(make_pair(capital[i],profits[i]) );
        }
        sort(vec.begin(),vec.end());
        if(vec[0].first>w)return w;
        priority_queue<int>pq;
        int i=0;
        while(k>0){
           while(i<n && vec[i].first<=w){
            pq.push(vec[i].second);
            i++;
           }
           if(pq.size()==0)break;
           auto maxiProfit=pq.top();
           pq.pop();
           w+=maxiProfit;
           k--;
           
        }
        return w;
    }
};
