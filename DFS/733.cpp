class Solution {
public:
    int m;
    int n;
    int fillColor;
    int xy[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        m = image.size();
        n = image[0].size();
        fillColor = newColor;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int color = image[sr][sc];
        dfs(image,visited,sr,sc,color);
        return image;
    }
    void dfs(vector<vector<int>>& image,vector<vector<bool>>& visited,int sr,int sc,int color){
        if(visited[sr][sc])
            return;
        visited[sr][sc] = true;
        if(image[sr][sc] != color)
           return;
        image[sr][sc] = fillColor;
        for(int i = 0;i < 4;i++){
            int x = sr+xy[i][0];
            int y = sc+xy[i][1];
            if(x>=0 && x<m && y>=0 && y<n)
                dfs(image,visited,x,y,color);
        } 
    }

};