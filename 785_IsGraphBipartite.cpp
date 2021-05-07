class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int V=graph.size();
        //vector<vector<int>> col(V, vector<int>(V,-1));
        vector<int> col(V,-1);
        
        bool flag=true;
        
        for(int i=0;i<V;i++)
        {
            if(col[i]==-1)
            {
                flag=dfs(graph,col,i,V,0);
                if(!flag)
                    return false;
            }
        }
        return true;
    }
    
    bool dfs(vector<vector<int>>& graph, vector<int> &col,int start,int V,int cr)
    {
        col[start]=cr;
        
        bool set=true;
        for(auto x:graph[start])
        {
            if(col[x]==-1)
            {
                set=dfs(graph,col,x,V,1-cr);
                if(!set)
                    return false;
            }
            else if(col[x]==col[start])
                return false;
        }
        return true;
    }
};
