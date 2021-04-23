class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        int c=numCourses;
        
        vector<vector<int>> adj(c);
        //Make adjacency list
        for(int i=0;i<n;++i)
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        
        int t=0;
        for(auto x:adj[t])
            cout<<x<<" ";
        
        cout<<endl;
        
        //Detect CYCLE..... if present then return empty array
        vector<int> ans;
        if(detectCycle(adj,c))
            return ans;
        
        stack<int> s;
        vector<bool> vis(c,false);
        
        //Apply DFS and find Topological Sort
        for(int i=0;i<c;i++)
        {
            if(!vis[i])
                dfs(adj,i,vis,s);
        }
        
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
    }
    
    void dfs(vector<vector<int>>& adj,int start,vector<bool> &vis,stack<int> &s)
	{
	    vis[start]=true;
	    for(auto node : adj[start])
	    {
	        if(!vis[node])
	            dfs(adj,node,vis,s);
	    }
	    s.push(start);
	}
    
    //Cycle detection
    bool detectCycle(vector<vector<int>>& adj, int V) {
	   	// code here
	   	bool visi[V], anc[V];
	   	for(int i=0;i<V;i++)
	   	{
	   	    visi[i]=false;
	   	    anc[i]=false;
	   	}
	   	
	   	for(int i=0;i<V;i++)
	   	{
	   	    if(!visi[i])
	   	        {
	   	            if(dfsCyclic(V,adj,visi,i,anc))
	   	                return true;
	   	        }
	   	}
	   	
	   	return false;
	}
	bool dfsCyclic(int V,vector<vector<int>>& adj,bool visi[],int start,bool anc[])
	{
	    visi[start]=true;
	    anc[start]=true;
	    
	    for(auto node: adj[start])
	    {
	        if(!visi[node])
	        {
	            if(dfsCyclic(V,adj,visi,node,anc))
	                return true;
	        }
	        else if(anc[node])
	            return true;
	    }
	    
	    anc[start]=false;
	    return false;
	}
    
};
