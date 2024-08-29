//CODE : DFS APPROACH
//WATCH MIK DFS SOLUTION
// WE NEED TO FIND THE NUMBER OF COMPONENTS . EACH COMPONENTS CONTAINS ALL THE ELEMENT THAT ARE EITHER IN THE SAME ROW OR IN SAME COLUMN.
class Solution {
public:
void dfs(int index,vector<vector<int>>& stones,vector<int>&visited){
    visited[index]=true;
    for(int i=0;i<stones.size();i++){
        int row=stones[index][0];
        int col=stones[index][1];
        if(visited[i]==false &&( stones[i][0]==row || stones[i][1]==col)){
            dfs(i,stones,visited);
        }
    }
}
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int numberOfComponents=0;
        vector<int>visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,stones,visited);
                numberOfComponents++;
            }
        }
        return n-numberOfComponents++;
    }
};
