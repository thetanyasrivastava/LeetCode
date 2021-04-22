lass Solution{
	public:
	/*  Function to find the number of strongly connected components
    *   using Kosaraju's algorithm
    *   V: number of vertices
    *   adj[]: array of vectors to represent graph
    */
    int kosaraju(int V, vector<int> adj[]) {
        //code here
        stack<int> s;
        bool vis[V];
        
        for(int i=0;i<V;i++)
            vis[i]=false;
        
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
                dfs(adj,V,vis,s,i);
        }
        
        
         for(int i=0;i<V;i++)
             vis[i]=false;
        
        
        
        //Reverse edges
        vector<int> adjrev[V];
        for(int v=0;v<V;v++)
        {
            for(auto u: adj[v])
                {
                    adjrev[u].push_back(v);
                }
        }
       
        
        int count=0;
       
        while(!s.empty())
        {
           int temp=s.top();
           s.pop();
                if(!vis[temp])
                   {
                       dfsrev(adjrev,V,vis,temp);
                       count++;
                   }
                    
        }
        
        return count;
    }
    void dfs(vector<int> adj[],int V,bool vis[],stack<int> &s, int start)
    {
        vis[start]=true;
        
        for(auto x:adj[start])
        {
            if(!vis[x])
                dfs(adj,V,vis,s,x);
        }
        
        s.push(start);
    }
    
    void dfsrev(vector<int> adjrev[],int V,bool vis[], int temp)
    {
        vis[temp]=true;
        
        for(auto x:adjrev[temp])
        {
            if(!vis[x])
                dfsrev(adjrev,V,vis,x);
        }
        
    }
    
};
