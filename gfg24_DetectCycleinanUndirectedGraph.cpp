class Solution {
public:
	bool isCycle(int V, vector<int>adj[]){
	    // Code here
	    bool vis[V];
	    for(int i=0;i<V;i++)
	    {
	        vis[i]=false;
	    }
	    
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	            {
	                if(dfs(V,adj,vis,i,-1))
	                    return true;
	            }
	    }
	    return false;
	}
	bool dfs(int V, vector<int>adj[],bool vis[],int start,int parent)
	{
	    vis[start] = true;
	    
	    for(auto node : adj[start])
	    {
	        if(!vis[node])
	        {
	            if(dfs(V,adj,vis,node,start))
	                return true;
	        }
	        else if(node!=parent)
	            return true;
	    }
	    return false;
	}
};
