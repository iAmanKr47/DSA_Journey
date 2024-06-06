
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if( n%groupSize !=0)return false;
        map<int,int>mp;
        for(auto i:hand)mp[i]++;

        while(mp.size()>0){
            int cnt=groupSize;
            int prev=-1;
            for(auto &ele:mp){
                 cnt--;
                 if(prev!=-1){
                    if(ele.first-prev !=1)return false;
                  }
                   prev=ele.first;
                   ele.second--;
                   if(ele.second==0)mp.erase(ele.first);
                   if(cnt==0)break;  
            }
            //what if all elements of map got traverse but cnt does not become zero this means it's not possible to form group  
            if(cnt!=0)return false; //sample test case [1,1,2,2,3,3] and groupSize=2 
        }
        
        return true;
    }
};
