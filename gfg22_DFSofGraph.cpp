class Solution {
public:

	vector<int>dfsOfGraph(int V, vector<int> adj[]){
	    // Code here
	    vector<int> v;
	    int start=0;
	    bool vis[V];
	    for(int i=0;i<V;i++)
	    {
	        vis[i]=false;
	    }
	    
	    dfs(V,adj,start,v,vis);
	    return v;
	}
	
	void dfs(int V, vector<int> adj[], int start, vector<int>& v, bool vis[])
	{
	    v.push_back(start);
	    vis[start]=true;
	    
	    for(auto x: adj[start])
	    {
	        if(!vis[x])
	            dfs(V,adj,x,v,vis);
	    }
	}
  };
