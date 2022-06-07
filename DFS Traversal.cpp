void dfs(int src,vector<int> &visited,vector<int> adj[],vector<int> &comp)
   {
       visited[src]=1;
       comp.push_back(src);
       for(auto n:adj[src])
       {
          if(!visited[n])dfs(n,visited,adj,comp);
       }
       
   }

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<int> adj[V];
    
    for(auto e:edges)
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    
    vector<int> visited(V,0);
    vector<vector<int>> ans;
    
    for(int i=0;i<V;i++)
    {
        vector<int> component;
        if(!visited[i])
        {
            dfs(i,visited,adj,component);
            sort(component.begin(),component.end());
            ans.push_back(component);
        }
    }
    
    return ans;
}
