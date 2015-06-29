#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>

using namespace std;

void show(const string &s)
{
    cout << s << endl;
}

int main()
{
    ifstream fin1("mat.txt");
    ifstream fin2("pat.txt");

    vector<string> list1;
    set<string> list2;
    list<string> list3;
    string s;

    cout << "Mat, please enter the names of your friends:\n";
    while(fin1 >> s)
        list1.push_back(s);
    sort(list1.begin(), list1.end());
    for_each(list1.begin(), list1.end(), show);

    cout << "Pat, please enter the names of your friends:\n";
    while(fin2 >> s)
        list2.insert(s);
    for_each(list2.begin(), list2.end(), show);

    cout << "the names of all friends:\n";
    /* list.merge can't be used, because list1 and list2 is not list type */
    merge(list1.begin(), list1.end(), list2.begin(), list2.end(), back_insert_iterator< list<string> >(list3) );
    for_each(list3.begin(), list3.end(), show);

    cout << "the unique names of all friends:\n";
    list3.unique();
    for_each(list3.begin(), list3.end(), show);

    return 0;
}
