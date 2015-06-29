#include <iostream>
#include <valarray>
#include <utility>
using namespace std;

typedef valarray<int> arrayint;
typedef pair<arrayint, arrayint> pairarray;

class wine: private string{
private:
    int years;
    pairarray pa;
public:
    wine(const char* l, int y, const int yr[], const int bot[])
        :string(l), years(y), pa(valarray<int>(yr, y), valarray<int>(bot, y))
    {
    }
    wine(const char* l, int y)
        :string(l), years(y), pa(valarray<int>(y), valarray<int>(y))
    {
    }

    const string& label(){
        return (string &)(*this);
    }

    int sum(){
        return (pa.second).sum();
    }
    void get_bottles()
    {
        int y, bot;
        cout << "Enter " << (string &)(*this)  << " data for " << years <<" :" << endl;
        for(int i = 0; i < years; i++){
            cout << "Enter year: ";
            cin >> y;
            cout << "Enter bottles for that year:";
            cin >> bot;
            (pa.first)[i] = y;
            (pa.second)[i] = bot;
        }
        cout << endl;
    }

    void show()
    {
        cout << "wine : " << (string &)(*this) << endl;
        cout << "\t" << "Year\t" << "Bottles"<<endl;
        for(int i = 0; i < years; i++)
            cout << "\t" <<  (pa.first)[i] <<"\t" <<  (pa.second)[i] <<endl;
    }
};

int main()
{
    const int YRS = 3;
    int y[YRS] = {1993, 1995, 1998};
    int b[YRS] = {48, 60, 72};
    wine more("Gushing Grape Red", YRS, y, b);
    more.show();
    cout << "Total bottles for " << more.label() << ": " << more.sum() << endl;

    char name[60];
    int years;
    cout << "Enter name of wine:";
    cin.getline(name, 60);
    cout <<"Enter number of years:";
    cin >> years;

    wine holding(name, years);
    holding.get_bottles();
    holding.show();

    cout << "Bye" << endl;
    return 0;
}

