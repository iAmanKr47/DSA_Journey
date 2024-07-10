//simulation
double averageWaitingTime(vector<vector<int>>& customers) {
        int n=customers.size();
        int currTime=customers[0][0]+customers[0][1];
        long long waiting=customers[0][1];
        for(int i=1;i<n;i++){
            int arrivalTime=customers[i][0];
            int orderPrepareTime=customers[i][1];
            waiting+=orderPrepareTime;
            
            if(currTime<arrivalTime){
                currTime=arrivalTime;
                currTime+=orderPrepareTime;
            }
            else{
                waiting+=currTime-arrivalTime;
                currTime+=orderPrepareTime;
            }
            

        }
        return (double)waiting/n;
    }
