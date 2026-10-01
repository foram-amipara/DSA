class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int stColor = image[sr][sc];
        if(stColor != color){
            dfs(image,sr,sc,stColor,color);
        }
        return image;

    }
    void dfs(vector<vector<int>>& image,int sr,int sc,int stColor,int color){
        if(sr<0 || sc<0 || sr>=image.size() || sc>=image[0].size() || image[sr][sc]!=stColor){
            return;
        }
        image[sr][sc]=color;
        dfs(image,sr+1,sc,stColor,color);
        dfs(image,sr,sc+1,stColor,color);
        dfs(image,sr-1,sc,stColor,color);
        dfs(image,sr,sc-1,stColor,color);
    }
};