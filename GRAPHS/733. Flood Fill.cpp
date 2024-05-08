//KEY POINT: take care of condition when current cell is already having the same color as we need to change.
//this states  that we have already visited that node  and we don't need to visit that again

void dfs(vector<vector<int>>&image,int sr, int sc, int &initialColor,int &color){
    if(sr<0||sr>=image.size() || sc<0 || sc>=image[0].size() ||image[sr][sc]!=initialColor || image[sr][sc]==color) 
    return;
    
    image[sr][sc]=color;
    dfs(image,sr+1,sc,initialColor,color);
    dfs(image,sr-1,sc,initialColor,color);
    dfs(image,sr,sc+1,initialColor,color);
    dfs(image,sr,sc-1,initialColor,color);
    

}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor=image[sr][sc];
        dfs(image,sr,sc,initialColor,color);
        return image;

    }
