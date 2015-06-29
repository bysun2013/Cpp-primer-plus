#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

void show(long a)
{
    cout << a << endl;
}

int reduce1(long ar[], int n)
{
    set<long> arset;
    int i;
    for(i=0; i<n; i++)
        arset.insert(ar[i]);

    set<long>::iterator it;
    for(i = 0, it = arset.begin(); it !=arset.end(); it++, i++)
        ar[i] = *it;

    return i;
}

int reduce2(long ar[], int n)
{
        sort(ar, ar+n);

        return (unique(ar, ar+n) - ar);
}

#define SIZE 20
int main()
{
    long ar[SIZE] = {10, 41, 12, 83, 14};
    int size = reduce2(ar, SIZE);

    cout << "The size of array is " << size << endl;

    for(int i=0; i < size; i++)
        cout << ar[i] << endl;

    return 0;
}
