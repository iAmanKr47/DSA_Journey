// count points for all squares of side 0 to till the conditions is satisfied
class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int visited[26]={0};
        map<int,vector<int>> mp;
        for(int i=0;i<points.size();i++){
            int key = max(abs(points[i][0]),abs(points[i][1])); 
            mp[key].push_back(i);
        }
        
        int ans = 0;
        for(auto& i:mp){
            for(auto& j:i.second){
                int chr = s[j]-'a';
                if(visited[chr]>0)
                    return ans;
                visited[chr]=1;
            }
            ans += i.second.size();
        }
        
        return ans;
    }
};
