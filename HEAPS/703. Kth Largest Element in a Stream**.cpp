
class KthLargest {
public:
int K;
    priority_queue<int, vector<int>, greater<int>> pq;//min heap
    KthLargest(int k, vector<int>& nums) {
        K=k; //just to use k globally anywhere;
        for(auto i:nums){
            pq.push(i);
            if(pq.size()>k)pq.pop();
        }
    }
    
    int add(int val) {
       pq.push(val);
        if(pq.size()>K)pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
