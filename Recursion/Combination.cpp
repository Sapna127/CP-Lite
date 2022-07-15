void helper(int n,int k,int i,vector<vector<int>> &ans, vector<int> &res){
        if(res.size()==k) {
            ans.push_back(res);
        }
        for(int j=i;j<=n;j++){
            res.push_back(j);
            helper(n,k,j+1,ans,res);
            res.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> res;
        helper(n,k,1,ans,res);
        return ans;
    }
