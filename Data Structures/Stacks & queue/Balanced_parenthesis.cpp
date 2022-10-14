#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool isBalanced(string s)
{
    if (s.size() == 0)
    {
        return true;
    }
    stack<char> str;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            str.push(s[i]);
        }
        else
        {
            if (str.size() == 0)
            {
                return false;
            }
                str.pop();
        }
    }
    if (str.size() == 0)
    {
        return true;
    }
    return false;
}
int main()
{
    string s;
    cin >> s;
    cout << ((isBalanced(s)) ? "true" : "false");
}