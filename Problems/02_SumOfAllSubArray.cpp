#include<iostream>
using namespace std;

int main(){
     int n;
    cin>>n;
    
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    int curr = 0;
 // Number of Sub arrays = n*(n+1)/2
    for(int i = 0;i<n; i++){ //Iterates each element
        curr = 0;
        for(int j=i; j<n; j++){ //Iterates each sub array
            curr += arr[j];
            cout<<curr<<" ";
        }
        cout<<endl;
    }
    return 0;
}