vector<string> ans;
   void permutation(string s,string tmp,vector<int> indices)
   {
       
       if(tmp.length()==s.length())
       {
           ans.push_back(tmp);
           return;
       }
       
       for(int i=0;i<s.length();i++)
       {
           if(find(indices.begin(),indices.end(),i)!=indices.end())continue;
           
           tmp.push_back(s[i]);
           indices.push_back(i);
           permutation(s,tmp,indices);
           
           tmp.pop_back();
           indices.pop_back();
       }
   }

vector<string> findPermutations(string &s) {
    // Write your code here.
    string tmp="";
    vector<int> indices;
    permutation(s,tmp,indices);
    
    return ans;
}
