//memoization
int mod = (int)1e9+7;
int findWaysUtil(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){

    if(ind == 0){
            if(target==0 && arr[0]==0)
                return 2;
            if(target==0 || target == arr[0])
                return 1;
            return 0;
    }
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    int notTaken = findWaysUtil(ind-1,target,arr,dp);
    
    int taken = 0;
    if(arr[ind]<=target)
        taken = findWaysUtil(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= (notTaken + taken)%mod;
}

int findWays(vector<int> &num, int k){
    int n = num.size();
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return findWaysUtil(n-1,k,num,dp);
}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    //int Tsum = accumulate(arr.begin(),arr.end());
    int Tsum = 0;
    for(int i : arr) Tsum+=i;
    int target = (Tsum - d)/2;
    if(Tsum-d<0 || (Tsum-d)%2) return false;
    return findWays(arr, target);
}




//tabulation

int mod = (int)1e9+7;
int findWays(vector<int> &num, int tar){
     int n = num.size();

    vector<vector<int>> dp(n,vector<int>(tar+1,0));
    
    if(num[0] == 0) dp[0][0] =2;  // 2 cases -pick and not pick
    else dp[0][0] = 1;  // 1 case - not pick
    
    if(num[0]!=0 && num[0]<=tar) dp[0][num[0]] = 1;  // 1 case -pick
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 0; target<=tar; target++){
            
            int notTaken = dp[ind-1][target];
    
            int taken = 0;
                if(num[ind]<=target)
                    taken = dp[ind-1][target-num[ind]];
        
            dp[ind][target]= (notTaken + taken)%mod;
        }
    }
    return dp[n-1][tar];
}
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    //int Tsum = accumulate(arr.begin(),arr.end());
    int Tsum = 0;
    for(int i : arr) Tsum+=i;
    int target = (Tsum - d)/2;
    if(Tsum-d<0 || (Tsum-d)%2) return false;
    return findWays(arr, target);
}



//space optimization

int mod = (int)1e9+7;
int findWays(vector<int> &num, int tar){
     int n = num.size();

    vector<int> prev(tar+1,0);
    
    if(num[0] == 0) prev[0] =2;  // 2 cases -pick and not pick
    else prev[0] = 1;  // 1 case - not pick
    
    if(num[0]!=0 && num[0]<=tar) prev[num[0]] = 1;  // 1 case -pick
    
    for(int ind = 1; ind<n; ind++){
        vector<int> cur(tar+1,0);
        for(int target= 0; target<=tar; target++){
            int notTaken = prev[target];
    
            int taken = 0;
                if(num[ind]<=target)
                    taken = prev[target-num[ind]];
        
            cur[target]= (notTaken + taken)%mod;
        }
        prev = cur;
    }
    return prev[tar];
}
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    //int Tsum = accumulate(arr.begin(),arr.end());
    int Tsum = 0;
    for(int i : arr) Tsum+=i;
    int target = (Tsum - d)/2;
    if(Tsum-d<0 || (Tsum-d)%2) return false;
    return findWays(arr, target);
}


