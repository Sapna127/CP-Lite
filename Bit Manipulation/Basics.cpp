#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
    int num;
    cin>>num;
    bitset<32> s(num);
    cout<<s<<endl; 
    cout<<s.to_string()<<endl; // converts number to string 
    cout<<s.to_ulong()<<endl; // to unsigned int
    cout<<s.to_ullong()<<endl; // to long long 
    cout<<s.set()<<endl; //set all bits on
    cout<<s.reset()<<endl; //set all bits off
    cout<<s.test(4)<<endl; //check if 4th bit is on?
    cout<<s.all()<<endl; // check if all bits are set
    cout<<s.none()<<endl; // " " " " " " off
    cout<<s.any()<<endl; //any bit is on ?


}
