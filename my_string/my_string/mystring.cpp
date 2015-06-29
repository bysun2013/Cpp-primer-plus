#include <iostream>
#include <cstring>

using namespace std;
#include "mystring.h"

int mystring::num_strings = 0;

mystring::mystring(){
	str = NULL;
	len = 0;
	num_strings++;
}

mystring::mystring(const mystring &s)
{
	len = s.len;
	str = new char[len+1];
	strcpy(str, s.str);
	num_strings++;
}

mystring::mystring(const char *s)
{
	len = strlen(s);
	str = new char[len+1];
	strcpy(str, s);
	num_strings++;
}

mystring::~mystring()
{
	delete [] str;
	--num_strings;
}


mystring & mystring::operator=(const mystring &s)
{
	if(this == &s)
		return *this;
	delete [] str;
	len = s.len;
	str = new char[len+1];
	strcpy(str, s.str);

	return *this;
}

mystring & mystring::operator=(const char *s)
{
	delete [] str;
	len = strlen(s);
	str = new char[len+1];
	strcpy(str, s);

	return *this;
}
char & mystring::operator[](int i)
{
	return str[i];
}
const char & mystring::operator[](int i) const
{
	return str[i];
}

bool operator<(const mystring &st1, const mystring &st2)
{
	return (strcmp(st1.str, st2.str) < 0);
}

bool operator>(const mystring &st1, const mystring &st2)
{
	return st2 < st1;
}

bool operator==(const mystring &st1, const mystring &st2)
{
	if(strcmp(st1.str, st2.str) == 0)
		return true;
	return false;
}

ostream & operator<<(ostream &os, const mystring &st)
{
	os << st.str;
	return os;
}

istream & operator>>(istream &is, mystring &st)
{
	char s[mystring::CINNUM];
	
	is.get(s, mystring::CINNUM - 1);
	if(is)
		st = s;
	while(is && is.get() != '\n')
		continue;

	return is;

}

int mystring::howmany()
{
	return num_strings;
}