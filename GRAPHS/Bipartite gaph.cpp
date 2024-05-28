/*
Using BFS
Approach:
Bipartite Graph means -> no adjacent nodes should have same color.
Make color array to store color either 0 / 1.
Put first node in queue with color 0, then pop it out and check for it's neighbours node
If any node found which has same adjacent node color then return false. simple!

KEY TAKEAWAY : Take care of componenets wala thing cz its possible graph is not connected
*/

class Solution {
public:
    bool bfs(int& start, vector<vector<int>>& graph, vector<int>& color) {
        queue<int> q;
        q.push(start);
        color[start] = 0;

        while (q.size() > 0) {
            auto front = q.front();
            q.pop();
            for (auto i : graph[front]) {
                int parentColor = color[front];
                // if unvisited
                if (color[i] == -1) {
                    color[i] = !parentColor;
                    q.push(i);
                }
                  //if adj node is visited and is of same color as parent 
                else if (color[i] == parentColor)
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1); // not visited:-1 ; color1:0 ; color2=1
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                int start = i;
                if (bfs(start, graph, color) == false)
                    return false;
            }
        }

        return true;
    }
};
