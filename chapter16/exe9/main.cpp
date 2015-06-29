#include <iostream>
#include <ctime>
#include <cstdlib>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

#define NUM 10000000

static void test()
{
    vector<int> vi0;

    for(int i=0;i<NUM;i++)
        vi0.push_back(rand());

    vector<int> vi(vi0);
    list<int> li(vi0.begin(), vi0.end());
    clock_t start, end;

    start = clock();
    sort(vi.begin(), vi.end());
    end = clock();
    cout <<"the time of sort algorithm on vector is "<< (double)(end - start)/CLOCKS_PER_SEC<< endl;

    start = clock();
    li.sort();
    end = clock();
    cout <<"the time of sort method on list is "<< (double)(end - start)/CLOCKS_PER_SEC<< endl;

    //reset the list value to vi0
    copy(vi0.begin(), vi0.end(), li.begin());

    start = clock();

    copy(li.begin(), li.end(), vi.begin());
    sort(vi.begin(), vi.end());
    copy(vi.begin(), vi.end(), li.begin());

    end = clock();
    cout <<"the time of sort on list using vector is "<< (double)(end - start)/CLOCKS_PER_SEC<< endl;
}

int main()
{
    cout << "Hello world!" << endl;

    test();
    return 0;
}
