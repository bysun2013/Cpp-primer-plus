#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

template <class T>
int reduce(T ar[], int n)
{
    set<T> arset;
    int i;
    for(i=0; i<n; i++)
        arset.insert(ar[i]);

    typename set<T>::iterator it;
    for(i = 0, it = arset.begin(); it !=arset.end(); it++, i++)
        ar[i] = *it;

    return i;
}

#define SIZE 20
int main()
{
    long ar[SIZE] = {10, 41, 12, 83, 14};
    string ss[SIZE] = {"strings", "strings", "hello", "world", "hello", "me", "me"};
    int size = reduce<long>(ar, SIZE);
    int str_size = reduce<string>(ss, SIZE);

    cout << "The size of array is " << size << endl;
        cout << "The size of string is " << str_size << endl;

    for(int i=0; i < size; i++)
        cout << ar[i] << endl;

    for(int i=0; i < str_size; i++)
        cout << ss[i] << endl;
    return 0;
}
