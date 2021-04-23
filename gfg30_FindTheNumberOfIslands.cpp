lass Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int rows=grid.size();
        if(rows==0)     //Empty grid boundary case
            return 0;
        int cols=grid[0].size();
        
        //Iterate for all cells of the array
        int no_of_islands=0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j]=='1')
                {
                    mark_current_island(grid,i,j,rows,cols);
                    no_of_islands++;
                }
            }
        }
        return no_of_islands;
    }
    
    void mark_current_island(vector<vector<char>> &matrix,int x,int y,int r,int c)
    {
        if(x<0 || x>=r || y<0 ||y>=c || matrix[x][y]!='1') //base case for matrix
            return;
        
        //mark current cell as visited
        matrix[x][y]='2';
        
        //make recursive calls in all 4 adjacent directions
        mark_current_island(matrix,x+1,y,r,c);  //DOWN
        mark_current_island(matrix,x,y+1,r,c);  //RIGHT
        mark_current_island(matrix,x-1,y,r,c);  //TOP
        mark_current_island(matrix,x,y-1,r,c);  //LEFT
        mark_current_island(matrix,x-1,y-1,r,c);    //top-left    
        mark_current_island(matrix,x+1,y+1,r,c);    //down-right
        mark_current_island(matrix,x+1,y-1,r,c);    //down-left
        mark_current_island(matrix,x-1,y+1,r,c);    //top-right
    
    }
};
