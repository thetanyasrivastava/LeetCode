class Solution {
public:
	bool isCyclic(int V, vector<int> adj[]) {
	   	// code here
	   	bool vis[V], anc[V];
	   	for(int i=0;i<V;i++)
	   	{
	   	    vis[i]=false;
	   	    anc[i]=false;
	   	}
	   	
	   	for(int i=0;i<V;i++)
	   	{
	   	    if(!vis[i])
	   	        {
	   	            if(dfs(V,adj,vis,i,anc))
	   	                return true;
	   	        }
	   	}
	   	
	   	return false;
	}
	bool dfs(int V,vector<int> adj[],bool vis[],int start,bool anc[])
	{
	    vis[start]=true;
	    anc[start]=true;
	    
	    for(auto node: adj[start])
	    {
	        if(!vis[node])
	        {
	            if(dfs(V,adj,vis,node,anc))
	                return true;
	        }
	        else if(anc[node])
	            return true;
	    }
	    
	    anc[start]=false;
	    return false;
	}
};
