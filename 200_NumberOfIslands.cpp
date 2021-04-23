class Solution {
public:
  /* DFS  
    //dfs + recursive
    //time: o(row * column)
    //space: o(row)
    
    int numIslands(vector<vector<char>>& grid) {
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
    
    void mark_current_island(vector<vector<char>> &grid,int x,int y,int r,int c)
    {
        if(x<0 || x>=r || y<0 ||y>=c || grid[x][y]!='1') //base case for matrix
            return;
        
        //mark current cell as visited
        grid[x][y]='2';
        
        //make recursive calls in all 4 adjacent directions
        mark_current_island(grid,x+1,y,r,c);  //DOWN
        mark_current_island(grid,x,y+1,r,c);  //RIGHT
        mark_current_island(grid,x-1,y,r,c);  //TOP
        mark_current_island(grid,x,y-1,r,c);  //LEFT
    }
    */
    
    //BFS
    //bfs + interative
    //time: o(row * column)
    //space: o(column)
    int numIslands(vector<vector<char>>& grid) {
        int rows=grid.size();
        if(rows==0)     //Empty grid boundary case
            return 0;
        int cols=grid[0].size();
        
       queue<pair<int,int>> q;
        
        int no_of_islands=0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j]=='1')
                {
                 no_of_islands++;
                grid[i][j]='0';
                    q.push(pair(i,j));
                    
                    while(!q.empty())
                    {
                        pair xy=q.front();
                        q.pop();
                        int x=xy.first;
                        int y=xy.second;
                        
                        if(x+1<rows && grid[x+1][y]=='1')
                        {
                            q.push(pair(x+1,y));
                            grid[x+1][y]='0';
                        }
                        if(x-1>=0 && grid[x-1][y]=='1')
                        {
                            q.push({x-1,y});
                            grid[x-1][y]='0';
                        }
                        if(y-1>=0 && grid[x][y-1]=='1')
                        {
                            q.push({x,y-1});
                            grid[x][y-1]='0';
                        }
                        if(y+1<cols && grid[x][y+1]=='1')
                        {
                            q.push({x,y+1});
                            grid[x][y+1]='0';
                        }
                    }
                }
            }
        }
        return no_of_islands;
                 
}
};
