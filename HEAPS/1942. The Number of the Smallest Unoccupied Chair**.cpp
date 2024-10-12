//INTERVAL BASED QUESTION
//TWO HEAP APPROACH

int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int targetFriendArrTime=times[targetFriend][0];
        int n=times.size();
        sort(times.begin(),times.end());
        if(times[0][0]==targetFriendArrTime)return 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > occupiedChair; //departureTime and chair number

        priority_queue<int,vector<int>,greater<int>>availableChairs;
        occupiedChair.push({times[0][1],0});

        for(int i=1;i<n;i++){
            int currArr=times[i][0];
            int currDep=times[i][1];
            auto top=occupiedChair.top();
            //ALL THE THE CHAIRS THAT ARE EMPTY TILL NOW PUT IT IN AVAILABLE CHAIRS LIST 
            while(occupiedChair.size()&&currArr>=top.first){
                occupiedChair.pop();
                availableChairs.push(top.second);
                top=occupiedChair.top();
            }
           //from the AVAILABLE CHAIRS LIST we have to select the min numbered chair
           //if there are available chairs 
            if(availableChairs.size()>0){
                occupiedChair.push({currDep,availableChairs.top()});
                 if(currArr==targetFriendArrTime)return availableChairs.top();
                availableChairs.pop();
            }
            //if no previous chair is empty take out new chair make current person sit on the new chair having number pq.size() {pq refers occupied chairs}
            else{
                occupiedChair.push({currDep,occupiedChair.size()});
                if(currArr==targetFriendArrTime)return occupiedChair.size()-1;
            }
        }
        return -1;
    }
