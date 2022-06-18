int maxProduct(vector<int>& A) {
      
  //  f[i] means maximum product that can be achieved ending with i
    vector<int> f(A.size());
        
  //g[i] means minimum product that can be achieved ending with i
    vector<int> g(A.size());
        
    f[0] = A[0];
    g[0] = A[0];
    int ans = A[0];
    for (int i = 1; i < A.size(); i++) {
        f[i] = max(max(f[i - 1] * A[i], g[i - 1] * A[i]), A[i]);
        g[i] = min(min(f[i - 1] * A[i], g[i - 1] * A[i]), A[i]);
        ans =  max(ans, f[i]);
    }
    return ans;
    }
