class Solution {
private:
    int m;
    int n;
    int fillColor;
    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,-1,1,0};
public:
    vector<vector<int> > floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        m = image.size();
        n = image[0].size();
        fillColor = newColor;
        vector<vector<int> > visited(m,vector<int>(n,0));
        int color = image[sr][sc];
        dfs(image,visited,sr,sc,color);
        return image;
    }
    bool valiadte(int x,int y){
        if(x < 0 || x >= m || y < 0 || y >= n)
            return false;
        return true;
    }
    void dfs(vector<vector<int> >& image,vector<vector<int> >& visited,int sr,int sc,int color){
        if(!valiadte(sr,sc))
            return;
        if(visited[sr][sc])
            return;
        if(image[sr][sc] != color)
            return;
        image[sr][sc] = fillColor;
        visited[sr][sc] = 1;
        for(int i = 0;i < 4;i++){
            int curx = sr + dx[i];
            int cury = sc + dy[i];
            dfs(image,visited,curx,cury,color);
        }
    }
};