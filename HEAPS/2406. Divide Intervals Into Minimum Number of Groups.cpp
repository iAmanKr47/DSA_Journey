//BRUTE FORCE(TLE)

int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        vector<int>lastInterval;
        lastInterval.push_back(intervals[0][1]);
        for(int i=1;i<n;i++){
            int currArr=intervals[i][0];
            int currDep=intervals[i][1];
            bool spaceFound=false;
            for(int j=0;j<lastInterval.size();j++){
                if(lastInterval[j]<currArr){
                    lastInterval[j]=currDep;
                    spaceFound=true;
                    break;
                }
            }
            if(spaceFound==false){
               lastInterval.push_back(currDep); 
            }
        }
        return lastInterval.size();
    }

//SORTING + MIN HEAP

int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        priority_queue<int,vector<int>,greater<int>>lastInterval;
        lastInterval.push(intervals[0][1]);
        for(int i=1;i<n;i++){
            int currArr=intervals[i][0];
            int currDep=intervals[i][1];
            auto top=lastInterval.top();
            if(top<currArr){
                lastInterval.pop();
                lastInterval.push(currDep);
            }
            else{
                 lastInterval.push(currDep);
            }
        }
        return lastInterval.size();
    }
