vector<int> BFS(int v, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<int> ans;
    vector<int> adj[v];
    vector<int> vis(v,0);
    
    for(auto p:edges)
    {
        adj[p.first].push_back(p.second);
        adj[p.second].push_back(p.first);
    }
    for(int i = 0; i < v; i++)
           sort(adj[i].begin(),adj[i].end());
    
    queue<int> q;
    
    for(int i=0;i<v;i++)
    {
        
        if(!vis[i])
        {
            q.push(i);
            vis[i]=1;
           // ans.push_back(i);
            while(!q.empty())
            {
                int n=q.size();
                for(int i=1;i<=n;i++)
                {
                    int top_node=q.front();
                    q.pop();
                    ans.push_back(top_node);
                    for(auto neighbour:adj[top_node])
                    {

                        if(!vis[neighbour])
                        {
                            q.push(neighbour);
                           // ans.push_back(neighbour);
                            vis[neighbour]=1;
                        }
                    }
                }
            }
        }
    }
    
    return ans;
    
}
