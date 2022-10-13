#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        // code here
        vector <int> arr(n,-1);
        for(int i =1; i<n;i++){
            int temp = INT_MAX;
            for(int j=i-1;j>=0;j--){
                if(a[j]<a[i]){
                    arr[i]=a[j];
                    break;
                }
            }
        }
        return arr;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        int a[n];
        for(int i =0; i<n; i++)
        cin>>a[i];

        Solution ob;
        vector<int> ans = ob.leftSmaller(n,a);
        for(int i =0; i<n; i++)
        cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
