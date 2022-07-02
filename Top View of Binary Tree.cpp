vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> topView;
   
   queue<pair<Node*,int>> q; // (node, line.no)
   
   if(root)q.push({root,0});
   
   map<int,int> m; // (line.no, node)
   
   m[0]=root->data;
   
   //marking each node with index of a vertical line while level traversal
   while(!q.empty())
   {
       //leftView.push_back(q.front()->data);
       
       int n=q.size();
       
       for(int i=1;i<=n;i++)
       {
           auto tmp=q.front();
           q.pop();
           if(tmp.first->left)
           {
               q.push({tmp.first->left,tmp.second-1});
               
               
               if(m.find(tmp.second-1)==m.end())m[tmp.second-1]=tmp.first->left->data;
           }
           if(tmp.first->right)
           {
               q.push({tmp.first->right,tmp.second+1});
              
              
              if(m.find(tmp.second+1)==m.end())m[tmp.second+1]=tmp.first->right->data;
           }
       }
   }
   
   
   for(auto e:m)
   {
       topView.push_back(e.second);
   }
   
   
   
    return topView; 
    }
