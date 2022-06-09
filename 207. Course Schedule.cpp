//detecting cycle
    bool dfs(int src,vector<int> adj[],vector<int> &visited,vector<int> &dfsVis)
    {
        visited[src]=1;
        dfsVis[src]=1;
        for(auto n:adj[src])
        {
            if(visited[n] & dfsVis[n])return true;
            else if(!visited[n])
                if(dfs(n,adj,visited,dfsVis))
                {
                    return true;
                }
        }
        
        dfsVis[src]=0;
        return false;
    }
    
    
    
    
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[numCourses];
        
        for(auto pre:prerequisites)
        {
            adj[pre[1]].push_back(pre[0]);
        }
        
        vector<int> visited(numCourses,0);
        vector<int> dfsVis(numCourses,0);
        
        for(int i=0;i<numCourses;i++)
        {
           if(!visited[i])
            {
                if(dfs(i,adj,visited,dfsVis))//cycle detected
                {
                    return false;
                }
            }
           
          
            
        }
        
        return true;
    }
