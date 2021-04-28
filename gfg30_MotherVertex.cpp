class Solution {
public:
	int findMotherVertex(int V, vector<int>adj[]){
	    // Code here
	    vector<int> vis(V,false);
	    
	    int recent_dfs_call;
	    
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	            dfs(adj,i,V,vis);
	            recent_dfs_call=i;
	        }
	    }
	    
	    
	    for(int i=0;i<V;i++)
	        vis[i]=false;
	   
	   dfs(adj,recent_dfs_call,V,vis);
	   
	   for(int i=0;i<V;i++)
	   {
	       if(!vis[i])
	            return -1;
	   }
	   
	   return recent_dfs_call;
	}
	
	void dfs(vector<int> adj[],int start,int V,vector<int>& vis)
	{
	    vis[start]=true;
	    
	    for(auto x: adj[start])
	    {
	        if(!vis[x])
	            dfs(adj,x,V,vis);
	    }
	}

};
