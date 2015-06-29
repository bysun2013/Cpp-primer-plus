#ifndef EMP_H_INCLUDED
#define EMP_H_INCLUDED

#include <iostream>
#include <string>

using std::string;
using std::ostream;
using std::cout;
using std::cin;
using std::endl;

class abstr_emp{
private:
    string  fname;
    string lname;
    string job;
public:
    abstr_emp():fname(), lname(), job() {}
    abstr_emp(const string &fn, const string &ln, const string &j)
        :fname(fn), lname(ln), job(j)   {}
    virtual void show_all() const;
    virtual void set_all();
    /* only show first name and last name */
    friend ostream & operator<<(ostream &os, const abstr_emp &e);
    virtual ~abstr_emp() = 0;
};

class employee: public abstr_emp{
public:
    employee()
        :abstr_emp() {}
    employee(const string &fn, const string &ln, const string &j)
        :abstr_emp(fn, ln, j){}
    virtual void show_all() const;
    virtual void set_all();
    virtual ~employee() { cout << "employee exits " << endl; }
};

class manager: virtual public abstr_emp{
private:
    int inchargeof;
protected:
    int incharge() const {
        return inchargeof;
    }
    int & incharge(){
        return inchargeof;
    }
public:
    manager()
        :abstr_emp(){}
    manager(const string &fn, const string &ln, const string &j, int ico = 0)
        :abstr_emp(fn, ln, j), inchargeof(ico) { }
    manager(const abstr_emp &e, int ico)
        :abstr_emp(e), inchargeof(ico) { }
    manager(const manager &m)
        :abstr_emp(m){
            inchargeof = m.inchargeof;
        }
    virtual void show_all() const;
    virtual void set_all();
    virtual ~manager() { cout << "manager exits " << endl;}
};

class fink : public virtual abstr_emp{
private:
    string reportsto;
protected:
    const string reports_to() const{
        return reportsto;
    }
    string& reports_to(){
        return reportsto;
    }
public:
    fink():abstr_emp(){ }
    fink(const string &fn, const string &ln, const string &j, const string &rpo)
        :abstr_emp(fn, ln, j), reportsto(rpo) { }
    fink(const abstr_emp &e, const string &rpo)
        :abstr_emp(e), reportsto(rpo) { }
    fink(const fink &e)
        :abstr_emp(e), reportsto(e.reportsto) { }

    virtual void show_all() const;
    virtual void set_all();
    virtual ~fink() { cout << "fink exits " << endl; }
};

class highfink: public manager, public fink
{
public:
    highfink()
        :abstr_emp(), manager(), fink() { }
    highfink(const string &fn, const string &ln, const string &j, const string &rpo, int ico)
        :abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo) { }
    highfink(const abstr_emp &e, const string rpo, int ico)
        :abstr_emp(e), manager(e, ico), fink(e, rpo) { }
    highfink(const fink &f, int ico)
        :abstr_emp(f), manager(f, ico), fink(f) { }
    highfink(const manager &m, string rpo)
        :abstr_emp(m), manager(m), fink(m, rpo) { }
    highfink(const highfink &h)
        :abstr_emp(h), manager(h), fink(h) { }

    virtual void show_all() const;
    virtual void set_all();
    virtual ~highfink() { cout << "highfink exits " << endl; }
};

#endif // EMP_H_INCLUDED
