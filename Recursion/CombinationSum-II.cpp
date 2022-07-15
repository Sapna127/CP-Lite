 void helper(int idx,vector<vector<int>> &ans, vector<int> &candi, vector<int> &ds, int target){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        for(int i=idx;i<candi.size();i++){
            if(i>idx && candi[i]==candi[i-1]) continue;
            if(candi[i]>target) break;
            ds.push_back(candi[i]);
            helper(idx+1,ans,candi,ds,target-candi[i]);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candi, int target) {
        sort(candi.begin(),candi.end());
        vector<vector<int>> ans;
        vector<int> ds;
        helper(0,ans,candi,ds,target);
        return ans;
    }
