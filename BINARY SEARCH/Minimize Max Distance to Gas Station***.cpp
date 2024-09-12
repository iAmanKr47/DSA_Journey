double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        int n=stations.size();
        priority_queue<pair<double,int>>pq;
        vector<int>insertedGasStations(n-1,0);//stores how many gas station is inserted at the i'th partition              
        
        for(int i=0;i<n-1;i++){
            pq.push({double(stations[i+1]-stations[i]),i});
        }
        while(k--){
            auto top=pq.top();
            pq.pop();
            int index=top.second;
            insertedGasStations[index]++;
            double diff=(stations[index+1]-stations[index]);
            double newDiff=diff/(double)(insertedGasStations[index]+1);
            pq.push({newDiff,index});
            
            
        }
        
        return (pq.top().first + 1e-4);
    }
