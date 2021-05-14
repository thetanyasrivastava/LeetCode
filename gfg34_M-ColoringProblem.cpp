//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool isSafe(int u,int c,bool graph[101][101],int V,int m,vector<int> color)
{
    for(int i=0;i<V;i++)
    {
        if(graph[u][i] && color[i]==c)      //neighbours of u and if they have same color -false
            return false;
    }
    return true;
}
bool mColoring(int u,bool graph[101][101],vector<int> &color,int V,int m)
{
    if(u==V)
        return true;
    
    for(int i=0;i<m;i++)
    {
        color[u]=i;
        if(isSafe(u,i,graph,V,m,color))     //to check whether adj nodes have different color
        {
            if(mColoring(u+1,graph,color,V,m))      //next node=u+1
                return true;
        }
        //color[u]=-1; - either at line 34 or 36, both are correct
    }
    color[u]=-1;
    return false;
}
bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    vector<int> color(V,-1);
    
        return mColoring(0,graph,color,V,m);
    
}
