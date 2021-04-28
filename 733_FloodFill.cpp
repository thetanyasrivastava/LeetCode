class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        flood(image,sr,sc,newColor,oldColor);
        return image;
    }
    
    void flood(vector<vector<int>>& image, int x, int y, int newColor, int oldColor)
    {
        if(x<0 || y<0 ||x>=image.size() || y>=image[0].size() ||
          image[x][y]!=oldColor || image[x][y]==newColor)
            return;
        
        image[x][y]=newColor;
        flood(image,x+1,y,newColor,oldColor);
        flood(image,x-1,y,newColor,oldColor);
        flood(image,x,y+1,newColor,oldColor);
        flood(image,x,y-1,newColor,oldColor);
    }
};
