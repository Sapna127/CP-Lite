void helper(vector<vector<int>> &ans, vector<int> &candi, int idx, int target, vector<int> &ds){
        if(idx==candi.size()) {
            if(target==0)
            ans.push_back(ds);
            return;
        }
        if(candi[idx]<=target){
            ds.push_back(candi[idx]);
            helper(ans,candi,idx,target-candi[idx],ds);
            ds.pop_back();
        }
        helper(ans,candi,idx+1,target,ds);
    }
   vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        helper(ans,candidates,0,target,ds);
        return ans;
    }
