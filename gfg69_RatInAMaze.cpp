class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> paths;
        
        if(m[n-1][n-1]==0 || m[0][0]==0)
        {
            return paths;
        }
        
        int row=0,col=0;
        string currpath="";
        
        maze(row,col,paths,currpath,m,n);
        sort(paths.begin(),paths.end());
        return paths;
    }
    
    void maze(int row,int col,vector<string> &paths,string &currpath,vector<vector<int>>& m,int n)
    {
        if(row==n-1 && col==n-1)
        {
            paths.push_back(currpath);
            return;
        }
        
        int r[]={-1,1,0,0};
        int c[]={0,0,-1,1};
        char dir[]={'U','D','L','R'};
        
        for(int i=0;i<4;i++)
        {
            if(isSafe(row+r[i],col+c[i],m,n))
            {
                m[row][col]=0;
                currpath.push_back(dir[i]);
                maze(row+r[i],col+c[i],paths,currpath,m,n);
                
                //backtracking
                m[row][col]=1;
                currpath.pop_back();
            }
        }
    }
    
    bool isSafe(int x,int y,vector<vector<int>>& m,int n)
    {
        if(x>=0 && y>=0 && x<n && y<n && m[x][y]==1)
            return true;
        
        return false;
    }
};
