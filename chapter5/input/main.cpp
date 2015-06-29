#include <iostream>

using namespace std;

const int len = 20;

int main()
{
    char name[len];

    cout << "1. Please input your name:" << endl;
    cin.get(name, len);
    cout<< name << endl;
    cin.get();
    cout << "2. Please input your name:" << endl;
    cin.get(name, len);
    cout<< name << endl;
    cin.get();

    cout << "3. Please input your name:" << endl;
    cin.getline(name, len);
    cout<< name << endl;

    return 0;
}
