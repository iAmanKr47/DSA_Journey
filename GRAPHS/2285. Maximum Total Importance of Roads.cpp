//TOPICS USED: GREEDY + GRAPH + HEAP

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        int importance=n;
        vector<int>degree(n,0);
        priority_queue<int>q;
        long long ans=0;
        //find degree
        for(auto v:roads){
            degree[v[0]]++;
            degree[v[1]]++;
        }
        for(auto i:degree){
            q.push(i);
        }
        while(q.size()>0){
            long long front=q.top();
            q.pop();
            ans+=(front*importance);
            importance--;
        }
        return ans;
    }
};
