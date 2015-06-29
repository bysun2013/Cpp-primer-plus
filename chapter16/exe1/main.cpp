#include <iostream>
#include <string>

using namespace std;

static bool huiwen(const string &s){
    int j = s.length() - 1;
    int i = 0;

    while(i < j){
        if(s[i] != s[j])
            break;
        i++;
        j--;
    }

    if(i >= j)
        return true;
    else
        return false;
}

int main()
{
    string s;

    cout << "Please enter a string:" << endl;
    cin >> s;

    cout << "this string is Palindrome ?" << (huiwen(s) ? "YES":"NO") << endl;

    return 0;
}
