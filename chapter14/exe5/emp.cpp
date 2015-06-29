#include "emp.h"
#include <string>
#include <iostream>

using namespace std;

void abstr_emp::show_all() const {
    cout << "Name:\t" << fname << " " << lname << endl;
}

void abstr_emp::set_all(){
    cout << "Please enter first name and last name: ";
    cin >> fname >> lname;
}

abstr_emp::~abstr_emp()
{
    cout << "abstr_emp exits " << endl;
}

ostream & operator<<(ostream &os, const abstr_emp &e)
{
    os << "<< Name: " << e.fname << " " << e.lname;
    return os;
}

void employee::show_all() const {
    cout << "Show Employee:" << endl;
    abstr_emp::show_all();
}

void employee::set_all(){
    cout << "Set Employee:" << endl;
    abstr_emp::set_all();
}

void manager::show_all() const{
    cout << "Show Manager:" << endl;
    abstr_emp::show_all();
    cout << "In charge of:\t" << inchargeof << endl;
}
void manager::set_all(){
    cout << "Set Manager:" << endl;
    abstr_emp::set_all();
    cout << "Please enter the number in charge of:" <<endl;
    cin >> inchargeof;
}

void fink::show_all() const{
    cout << "Show Fink:" << endl;
    abstr_emp::show_all();
    cout << "reportsto:\t" << reportsto << endl;
}
void fink::set_all(){
    cout << "Set Fink:" << endl;
    abstr_emp::set_all();
    cout << "Please enter reportsto: ";
    cin >> reportsto;
}

void highfink::show_all() const{
    cout << "Show highfink:" << endl;
    abstr_emp::show_all();
    cout << "In charge of:\t" << incharge() << endl;
    cout << "reportsto:\t" << reports_to() << endl;
}
void highfink::set_all(){
    cout << "Show highfink:" << endl;
    abstr_emp::set_all();
    cout << "Please enter the number in charge of: ";
    cin >> incharge();
    cout << "Please enter reportsto: ";
    cin >> reports_to();
}
