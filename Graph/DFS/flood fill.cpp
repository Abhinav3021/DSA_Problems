class Solution {
public:
    void dfs(int i, int j,vector<vector<int>>& image, int newcolor,int currentColor){
        int n=image.size();
        int m=image[0].size();
        if(i<0 || j<0){return ;}
        if(i>=n || j >=m){return ;}
        if(image[i][j]!=currentColor){return ;}
        image[i][j]=newcolor;

        dfs(i-1,j,image,newcolor,currentColor);
        dfs(i+1,j,image,newcolor,currentColor);
        dfs(i,j+1,image,newcolor,currentColor);
        dfs(i,j-1,image,newcolor,currentColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        if(image[sr][sc]!=color){
            dfs(sr,sc,image,color,image[sr][sc]);
        }
        return image;
    }
};