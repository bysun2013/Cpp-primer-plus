#include <iostream>
#include <valarray>
#include <utility>
using namespace std;

class wine{
private:
    typedef valarray<int> arrayint;
    typedef pair<arrayint, arrayint> pairarray;

    string name;
    int years;
    pairarray pa;
public:
    wine(const char* l, int y, const int yr[], const int bot[])
        :name(l), years(y), pa(valarray<int>(yr, y), valarray<int>(bot, y))
    {
    }
    wine(const char* l, int y)
        :name(l), years(y), pa(valarray<int>(y), valarray<int>(y))
    {
    }

    string label(){
        return name;
    }

    int sum(){
        return (pa.second).sum();
    }
    void get_bottles()
    {
        int y, bot;
        cout << "Enter " << name << " data for " << years <<" :" << endl;
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
        cout << "wine : " << name << endl;
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
