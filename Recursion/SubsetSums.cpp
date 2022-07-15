 void helper(vector<int> &ans, vector<int> &arr, int n, int idx, int sum){
        if(idx==n) ans.push_back(sum); return;
        helper(ans,arr,n,idx+1,sum+arr[idx]); //pick
        helper(ans,arr,n,idx+1,sum); //not pick
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        helper(ans,arr,N,0,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
