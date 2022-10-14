#include<bits/stdc++.h>
using namespace std;
#define lli long long int

lli power(lli x, lli y, lli p) {
    lli res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1) res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int main() {
    cout<<power(2, 3, 1000000007);    // outputs (8 % 1000000007) => 8
}