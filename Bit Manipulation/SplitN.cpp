#include<bits/stdc++.h>
#define nl "\n"
typedef long long ll;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define fl(i, a, b) for (ll i = a; i < b; i++)
#define yes cout<<"YES \n"
#define no cout<<"NO \n"
#define all(v) (v).begin(),(v).end()    
#define inputstring(n,s) ll n;cin>>n; string s; cin>>s;

#define inpvec        \
    ll n;             \
    cin >> n;         \
    vector<ll> v(n);  \
    for (auto &i : v) \
        cin >> i;

using namespace std;

void solve(){
	ll n;
	cin>>n;
	cout<<__builtin_popcountll(n)-1<<nl;
}


int main(){
    fastio();

    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    // solve();

}
