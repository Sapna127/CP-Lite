//recursion  - top down
fib(int n){
if(n<=1) return n;
return fib(n-1) + fib(n-2);
}

//dp memoization
vector<int> dp(n+1,-1);  //1
fib(int n, vector<int> &dp){
if(n<=1) return n;
if(dp[n]!=-1) return dp[n]; //2
return dp[n]=fib(n-1,dp)+fib(n-2,dp); //3
}

// tabulation
// without recursion stack space
dp[0]=0, dp[1]=1;
for(int i=2;i<=n;i++){
dp[i]=dp[i-1]+dp[i-2];
}
return dp[n];

// without extra space space optimization 
int pre2 = 0, pre1 = 1;

for(int i=3;i<=n;i++){
int curr = prev2+prev1;
prev2=prev1;
prev1=curr;
}
return prev1;
