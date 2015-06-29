#include <iostream>

using std::ostream;
using std::istream;

class mystring
{
private:
	char *str;
	int len;
	static int num_strings;
	static const int CINNUM = 80;
public:
	mystring();
	mystring(const mystring &s);
	mystring(const char *s);
	~mystring();
	int length() const{ return len; }

	mystring & operator=(const mystring &s);
	mystring & operator=(const char *s);
	char & operator[](int i);
	const char & operator[](int i) const;

	friend bool operator<(const mystring &st1, const mystring &st2);
	friend bool operator>(const mystring &st1, const mystring &st2);
	friend bool operator==(const mystring &st1, const mystring &st2);
	friend ostream & operator<<(ostream &os, const mystring &st);
	friend istream & operator>>(istream &is, mystring &st);

	static int howmany();
};

