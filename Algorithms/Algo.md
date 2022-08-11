
 (Kadane's Algorithm)

We can observe that in the previous approach, dp[i] only depended on dp[i-1]. 
So do we really need to maintain the whole dp array of N elements? One might see the last line of previous solution and say that 
we needed all elements of dp at the end to find the maximum sum subarray. But we can simply optimize that by storing the max at each iteration 
instead of separately calculating it at the end.

Thus, we only need to maintain curMax which is the maximum subarray sum ending at i and maxTillNow which is the maximum sum we have seen till now. 
And this way of solving this problem is what we popularly know as Kadane's Algorithm
