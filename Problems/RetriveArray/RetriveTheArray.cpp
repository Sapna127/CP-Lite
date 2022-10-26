#include <bits/stdc++.h>//for including all the header files
using namespace std;
typedef long long ll;// definign long long as ll
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
cout<<endl;
}
}