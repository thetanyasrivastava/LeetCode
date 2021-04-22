class Solution{
	public:
	// Function to construct and print MST for
    // a graph represented using adjacency
    // list representation, with V vertices.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        bool vis[V];
        int dis[V];
        int parent[V];
        
        for(int i=0;i<V;i++)
        {
            vis[i]=false;
            dis[i]=INT_MAX;
        }
        dis[0]=0;  parent[0]=-1;
        
        set<pair<int,int>> s;       //{w,node}
        
        for(int i=0;i<V;i++)
        {
            if(i==0)
                s.insert({0,0});
            else
                s.insert({INT_MAX,i});
        }
        
        while(!s.empty())
        {
            //Extract front elements
            auto itr=*(s.begin());
            int u=itr.second;
            vis[u]=true;
         
            //delete the previous pair of node
            s.erase(itr);
            
            //relax its neighbours (v) which are not visited
            //update the weights
            for(int v=0;v<adj[u].size();v++)
            {
                if(!vis[adj[u][v][0]])
                {
                    if(dis[adj[u][v][0]] > adj[u][v][1])
                    {
                        auto curr=s.find({dis[adj[u][v][0]], adj[u][v][0]});
                        s.erase(curr);
                        
                        dis[adj[u][v][0]]=adj[u][v][1];
                        s.insert({dis[adj[u][v][0]],adj[u][v][0]});
                        parent[adj[u][v][0]]=u;
                    }
                }
            }
        }
        
        int sum=0;
        for(int i=0;i<V;i++)
            sum+=dis[i];
            
        return sum;    
    }
};
