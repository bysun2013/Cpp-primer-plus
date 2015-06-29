#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void show(int a)
{
    cout << a << "  ";
}

vector<int> lotto(int range, int n)
{
    vector<int> v1;
    int i;

    for(i=1;i<=range;i++)
        v1.push_back(i);

    random_shuffle(v1.begin(), v1.end());

    return vector<int>(v1.begin(), v1.begin() + n);
}

int main()
{
    int range, num;
    cout << "Please enter range and number: \n";
    cin >> range >> num;

    vector<int> v1 = lotto(range, num);

    for_each(v1.begin(), v1.end(), show);
    return 0;
}
