int timeRequiredToBuy(vector<int>& tickets, int k) {
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=min(tickets[k],tickets[i]);
        }
        sum+=tickets[k];
        for(int i=k+1;i<tickets.size();i++){
            sum+=min(tickets[k]-1,tickets[i]);
        }
        return sum;
    }
