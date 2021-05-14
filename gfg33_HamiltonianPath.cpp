class Solution
{
    public:
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        // code here
        vector<vector<int>> g(N+1);
        for(auto x: Edges)
        {
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        vector<bool> vis(N+1,false);
        int count;
        for(int i=0;i<N;i++)
        {
            count=1;
            vis[i]=false;
            if(backtracking(N,g,i,vis,count))
                return true;
            
        }
        return false;
    }
    
    bool backtracking(int N,vector<vector<int>> g,int u,vector<bool> vis,int count)
    {
        vis[u]=true;
        //count++;
        
        if(count==N)
            return true;
            
        for(int v:g[u])
        {
            if(!vis[v])
            {
                if(backtracking(N,g,v,vis,count+1))
                    return true;
                //vis[v]=0;
            }
        }
        /*for(int j=0;j<g[u].size();j++)
    	{
    		if(vis[g[u][j]]==0)
    		{
    			if(backtracking(N,g,g[u][j],vis,count+1))
    			return true;
    			vis[g[u][j]]=0;
    		}
    	}*/
    	//return false;
        
        vis[u]=false;
        return false;
    }    
};
 
