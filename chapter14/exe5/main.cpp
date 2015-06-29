#include <iostream>

using namespace std;

#include "emp.h"

int main()
{
    {
        employee em("Trip", "Harris", "Thumper");
        cout << em <<endl;
        em.show_all();

        manager ma("Amorphia", "Spinderagon", "Nuancer", 5);
        cout <<ma << endl;
        ma.show_all();

        fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
        cout << fi << endl;
        fi.show_all();

        highfink hf(ma, "Curky Kew");
        hf.show_all();
        cout << "Press a key for next phrase:\n";
        cin.get();

        highfink hf2;
        hf2.set_all();

        cout << "Use an abstr_emp *pointer:\n";
        abstr_emp *tri[4] = {&em, &fi, &hf, &hf2};
        for(int i = 0; i <4; i++)
            tri[i]->show_all();
    }
    return 0;
}
