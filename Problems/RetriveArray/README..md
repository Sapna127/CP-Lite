[Link to the Question](https://www.codechef.com/START45D/problems/ARRAYRET/)

# Problem Statement
<pre>
Chef has an array A of length N.

Let f(i) denote the sum A1 + A2 + ... + Ai and let g(i) denote the sum A + Ai+1 +... + AN.

Chef creates another array В of length N such that Bi = f(i) + g(i) for all 1 <= i <= N.

 Now, Chef has lost the original array A and needs your help torecover it, given array В. It is guaranteed that Chef has obtained the array В from a valid array A.
</pre>

## Input Format
<pre>
The first line contains a single integer T — the number of test cases.Then the test cases follow.

The first line of each test case contains an integer N -- the size of the array A.

The second line of test case contains N space-separated integers B1,B2,....,BN denoting the array B.
</pre>

## Output Format
<pre>
For each testcase, output N space seperated
integers A1, A2,..., AN denoting the array A.

Note that 1 <= A <= 10^5 must hold for all 1 <= i <= N and it is guaranteed that a valid array A that meets these constraints exists.

If there are multiple answers, output any.
</pre>

## Constraints
<pre>
i.  1<=T<=1000

ii. 1<=N<=10^5

ii. 1<=Bi<=2*10^10

iv. The sum of N over all test cases does not exceed 10^5.

v.  1<=Ai<=10^5

It is guaranteed that a valid array A always exists.

Th sum of N over all test cases.
</pre>

# Algorithm
<pre>
1.Take input for T,the number of test cases.Write an outer loop
 for iterating over T.

3.Take input for N, the size of array, and declare an array of the given size. Take input for the declared array.

2.Find out the minimum element of the array.

3.Find out the sum of deviation from minimum element (for each element).

4.Compute the first original element of the array by this logic:
val=(Minimum element of array-sum of deviation over the array)/(sizeof array +1)

5.Compute each orginal element by adding the deviation with each element.In this fashion, the whole original array will be generated.

6.Display each original element.After each test case is completed, jump to the next line.

7.END

</pre>

# Space and Time Complexity
## Space Complexity
O(N)
## Time Complexity

# Code
O(10^5)
```cpp
#include <bits/stdc++.h>//for including all the header files
using namespace std;
typedef long long ll;// defining long long as ll
const ll m=1e7+10;
ll  arr[m];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
ll t;
cin>>t;
while(t--){
ll n;
cin>>n;
ll arr[n];
for(ll i=0;i<n;i++){
  cin>>arr[i];//taking array input
}
ll sum=0;
ll mn=*min_element(arr,arr+n);//calculating minimum element in the array
for(ll i=0;i<n;i++){
sum+=(arr[i]-mn); //sum of deviation from minimum element
}
ll l=sizeof(arr)/sizeof(arr[0]);
ll val=(mn-sum)/(l+1);
for(ll i=0;i<n;i++){
  ll diff=arr[i]-mn;
  cout<<(val+diff)<<" "; //retriving the original element
}
cout << endl;
}
}
```
