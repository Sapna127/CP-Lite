#include <iostream>
using namespace std;

int getBit(int n,int pos){
    return((n & (1<<pos))!=0);
}
int setBit(int n, int pos){
    return (n|(1<<pos));
}
int clearBit(int n, int pos){
    int mask=~(1<<pos);
    return (n & mask);
}
int updateBit(int n, int pos, int value){
    int mask= ~(1<<pos);
    n = n & mask;
    return (n| (value<<pos));
}
int main()
{
    cout<<"get bit is: "<<getBit(5,2)<<endl;
    cout<<"set bit is: "<<setBit(5,1)<<endl;
    cout<<"cleared bit is: "<<clearBit(5,2)<<endl;
    cout<<"updated bit is: "<<updateBit(5,1,1)<<endl;
return 0;
}