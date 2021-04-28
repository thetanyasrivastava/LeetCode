class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.size()==0)
            return 0;
        int time=0;
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        
        int size=q.size();
        while(size>0)
        {
            for(int i=0;i<size;i++)
            {
                pair<int,int> p=q.front();
                q.pop();
                
                pushNeighbours(grid,q,p);
            }
            size=q.size();
            if(size>0)
                time++;
        }
        
        //if we cannot reach oranges that are still fresh
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                    return -1;
            }
        }
        return time;
    }
    
void pushNeighbours(vector<vector<int>> &grid,queue<pair<int,int>> &q,pair<int,int> p){
    int x=p.first;
    int y=p.second;
    
    int r=grid.size();
    int c=grid[0].size();
    
    int X[]={-1,1,0,0};
    int Y[]={0,0,-1,1};
    
    for(int i=0;i<4;i++)
    {
        int a=x+X[i];
        int b=y+Y[i];
        if(a>=0 && a<r && b>=0 && b<c && grid[a][b]==1)
        {
            q.push({a,b});
            grid[a][b]=2;
        }
        /*if(a<0 || a>=r || b<0 || b>=c || grid[a][b]!=1)
        {
            continue;
        }
        q.push({a,b});
        grid[a][b]=2;*/
    }
}
};
