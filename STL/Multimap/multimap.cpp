#include <bits/stdc++.h>
using namespace std;

int main(){
    multimap<int, int> mmap1;
    mmap1.insert(pair<int, int>(1, 40));
    mmap1.insert(pair<int, int>(2, 30));
    mmap1.insert(pair<int, int>(3, 60));
    mmap1.insert(pair<int, int>(4, 20));
    mmap1.insert(pair<int, int>(5, 50));
    mmap1.insert(pair<int, int>(6, 50));

    
    multimap<int, int>::iterator itr;
    cout << "\nThe map mmap1 is : \n";
    cout << "\tKEY\tELEMENT\n";
    for (itr = mmap1.begin(); itr != mmap1.end(); ++itr) {
        cout << '\t' << itr->first << '\t' << itr->second
             << '\n';
    }
    cout << endl;
    multimap<int, int> mmap2(mmap1.begin(), mmap1.end());
    cout << "\nThe map mmap2 after"
         << " assign from mmap1 is : \n";
    cout << "\tKEY\tELEMENT\n";
    for (itr = mmap2.begin(); itr != mmap2.end(); ++itr) {
        cout << '\t' << itr->first << '\t' << itr->second
             << '\n';
    }
    cout << endl;
    cout << "\nmmap2 after removal of"
            " elements less than key=3 : \n";
    cout << "\tKEY\tELEMENT\n";
    mmap2.erase(mmap2.begin(), mmap2.find(3));
    for (itr = mmap2.begin(); itr != mmap2.end(); ++itr) {
        cout << '\t' << itr->first << '\t' << itr->second
             << '\n';
    }
    int num;
    num = mmap2.erase(4);
    cout << " \nmmap2.erase(4) : ";
}