#include <iostream>
#include <string>
#include <cctype>

using namespace std;

/* s2 must be empty */
static int convert_string(const string &s1, string &s2)
{
    int i = 0;

    while(i < s1.length())
    {
        if(isalpha(s1[i]))
            s2.push_back(tolower(s1[i]));
        i++;
    }

    return 0;
}

static bool huiwen(const string &s)
{
    int j = s.length() - 1;
    int i = 0;

    while(i < j)
    {
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
    string s1, s2;

    cout << "Please enter a string:" << endl;
    getline(cin, s1);

    convert_string(s1, s2);

    cout << s1<< endl;
    cout << s2 << endl;
    cout << "this string is Palindrome ?" << (huiwen(s2) ? "YES":"NO") << endl;

    return 0;
}
