class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
	bool isCycle(int V, vector<int>adj[])
	{
	    // Code here
	    vector<bool> vis(V,false);
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	            //if(dfs(i,adj,vis,V,-1))
	            if(bfsCycle(i,adj,vis,V))
	                return true;
	        }
	    }
	    return false;
	}
	//BFS
	bool bfsCycle(int s,vector<int> adj[],vector<bool> &vis,int V){
	    queue<pair<int,int>> q;
	    
	    vis[s]=true;
	    q.push({s,-1});
	    
	    while(!q.empty())
	    {
	        int node=q.front().first;
	        int parent=q.front().second;
	        
	        q.pop();
	        
	        for(auto x: adj[node])
	        {
	            if(!vis[x])
	            {
	                vis[x]=true;
	                q.push({x,node});
	             }
	             else if(x!=parent)
	                return true;
	        }
	    }
	    return false;
	}
};
