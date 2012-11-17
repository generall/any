//============================================================================
// Name        : any.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class A
{
public:
	virtual void print()=0;
	virtual ~A()
	{
	}
	;
};

template<class T>
class B: public A
{
public:
	T t;
	void print()
	{
		cout << t << std::endl;//unknown error in eclipse;
	}
	B(T _t)
	{
		t = _t;
	}
private:
	B()
	{
	}
};

class any
{
public:
	A* ref;
	template<class T>
	any(T t)
	{
		ref = new B<T>(t);
	}
	void print()
	{
		ref->print();
	}
	template<class T>
	T operator=(T t)
	{
		if (ref != NULL)
			delete ref;
		ref = new B<T>(t);
		return t;
	}
	~any()
	{
		delete ref;
	}
	any()
	{
		ref = NULL;
	}
};

int main()
{
	any t=123;
	t.print();
	any s="str";
	s.print();
	//cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
