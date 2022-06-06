graphNode *dfs(graphNode *node,map<graphNode*,graphNode*> &m)
{
    
    graphNode *clone=new graphNode(node->data);
    m[node]=clone;
    
    vector<graphNode *> neighbours;
    for(auto n:node->neighbours)
    {
        if(m.find(n)!=m.end()) //already cloned and stored in map
        {
            neighbours.push_back(m[n]);
        }
        else
        {
             neighbours.push_back(dfs(n,m)); //recur for that node
        }
    }
    
    clone->neighbours=neighbours;

    return clone;
}

graphNode *cloneGraph(graphNode *node)
{
    // Write your code here.
    map<graphNode*,graphNode*> m;
    
    return dfs(node,m);
    
}
