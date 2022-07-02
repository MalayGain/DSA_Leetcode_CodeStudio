vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int, vector<int> > m;  // when iterate map, key is already the order of vertical-axis
	queue<pair<int, TreeNode*> > q; // for level traversal
	q.push(make_pair(0, root));  // root default x-axis is 0
        
	while(!q.empty()) {
		multiset<pair<int, int> > tmp;  // k: vertical-axis, v:val Already solved the case when the position is ths same
		int len=q.size();
		for(int i=0;i<len;++i) {
			auto p=q.front();q.pop();
			tmp.insert(make_pair(p.first, p.second->val));
			if (p.second->left) q.push(make_pair(p.first-1, p.second->left));
			if (p.second->right) q.push(make_pair(p.first+1, p.second->right));
		}

		for(auto p : tmp) m[p.first].push_back(p.second); //set keeps the nodes in the same row and same column in sorted order
    }
        
	vector<vector<int> > ans;
	for(auto v : m) ans.push_back(v.second);
	return ans;
        
    }
