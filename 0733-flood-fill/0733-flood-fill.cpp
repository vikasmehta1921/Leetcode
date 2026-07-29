class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int newcolour , int oldcolour){
        if(i<0 || j <0 || i >= image.size() || j >= image[0].size() || image[i][j] == newcolour || image[i][j] != oldcolour){
            return;

        }
        image[i][j] = newcolour;
        dfs(image , i-1 , j , newcolour , oldcolour);
        dfs(image , i , j+1 , newcolour , oldcolour);
        dfs(image , i+1 , j , newcolour , oldcolour);
        dfs(image , i , j-1 , newcolour , oldcolour);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image,sr,sc,color,image[sr][sc]);
        return image;
        
    }
};