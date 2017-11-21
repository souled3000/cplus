/*
 * template.cpp
 *
 *  Created on: 2017年8月16日
 *      Author: juliana
 */

#include <iostream>
#include <string>
#include "stock00.h"
using namespace std;

static int global = 100;
template<class c>
void f_class(c a, c b) {
	cout << a << endl;
	cout << b << endl;
}

struct where {
	double x;
};
std::ostream & operator<<(std::ostream & os, where w) {
	os << w.x << endl;
	return os;
}
void f_other() {
	static int global = 1;
	cout << "other local global:" << global << endl;
	cout << "other static global:" << ::global << endl;
	cout << "other" << endl;
	where w = { 1.1 };
	cout << w;
	where *ww = new where;
	char * cp = new char[5];
	delete ww;
	delete cp;
	double *dd = new double[5];
	cout << *(dd + 1) << " " << dd[1] << endl;
	delete dd;

}
/***
 * c++11 supported the keyword 'decltype'
 */
//void f_decltype() {
//	int a = 100;
//	decltype(a) y;
//}
void f_stock() {
	Stock stock;
	stock.buy(100, 3.5);
	stock.lawer.set_name("ych");
	stock.acquire("lchj", 100, 20.9);
	stock.show();
	Stock d = Stock();
	d.setCo("d");
	d.show();
	Stock *e = new Stock;
	e->setCo("e");
	e->show();

	Stock a = Stock("a ", 1, 1.1);
	a.show();
	Stock b("b ", 1, 1.1);
	b.show();
	Stock *c = new Stock("c ", 1, 1.1);
	c->show();

	Stock x = a + b;
	x.setCo("XXXXXXXXXXXXX");
	x.show();

	Stock z = 3.5 + x;
	z.setCo("ZZZZZZZZZZZZZZZ");
	z.show();
	x.show();

	Stock y = c->operator +(d);
	y.show();

	cout << x << y << z;

	delete (e);
	delete (c);

	const Stock cs;
//	cs.setCo("xx");
	cs.show();

	Stock h;
//	h="HC";//no match for 'operator='(operand types are 'Stock' and 'const char[3]'
	h = (std::string) "HC"; //no match explicit Stock::Stock(std:string s);
	h.show();

	h = (Stock) "HHC";
	h.show();

	Stock j("JJJC");
	j.show();
}

void f_person() {
	Person p;
	p.name = "wwww";
	Person pp = p;
	p = pp;
	cout << p.name << endl;
	cout << pp.name << endl;

	C x;
	x.s = "ccc";
	C xx = x;
	cout << &x.s << "  " << x.s << endl;
	cout << &xx.s << "  " << xx.s << endl;

	C y;
	y.s = "ccc";
	C yy;
	yy = y;
	cout << &y.s << "  " << y.s << endl;
	cout << &yy.s << "  " << yy.s << endl;

}
const int & f_const_int(const int & i) {
//	i=1000;
	return i;
}
int f_int() {
	return 100;
}
int & f_noconst(int & a) {

//reference to local variable 'a' returned [-Wreturn-local-addr]
//int & f_noconst(int & a) {

//reference to local variable 'x' returned [-Wreturn-local-addr]
//	int x = 3;
//	return x;

	return a;
}
int * f_intpoint(int * a) {
	return a;
}
const int * f_const_intpoint() {
	int * p;
	int a = 100;
	p = &a;
	return p;
}
int * const f_const_pointint() {
	int * p;
	int a = 1000;
	p = &a;
	return p;
}

void call_f_const() {
	int a = 100;
	f_noconst(a) = 1000;
	//assignment of read-only location 'f_const_int(a)'
	//	f_const_int(a)=100;
	int *p = &a;
	f_intpoint(p);
	f_const_intpoint();
	f_const_pointint();

	//测试成员函数f() const，f()中不能修改类成员，
	//const类实例只能调用f() const方法，因为f1可以修改成员
	const B b = B();
//	b.f1();
	b.f();
//	f_int()=100;

	//测试调用哪个复制构造函数
	C c = C("ssss");
	C cc = c;
	cout << &cc << " " << &c << endl;
	const C c1 = C("ssss");
	C cc1 = c1;
	cout << &cc1 << " " << &c1 << endl;
	C ccc = "cccc";	// invoke C(char * s);
	std::string s = c;	// invoke operator std:string();
	cout << "C's len :" << sizeof(C) << endl;
	cout << "B's len :" << sizeof(B) << endl;
	cout << "D's len :" << sizeof(D) << endl;
	cout << "Stock's len :" << sizeof(Stock) << endl;
	cout << "Lawer's len :" << sizeof(Lawer) << endl;
}
const int & f_xx(const int & i) {
	int b = 1999;
//	const int & a = i;
	const int & a = b;
	return a;
}
void point() {
	const int * p;
	int a = 100;
	int b = 300;
	p = &a;
	p = &b;
//	*p = 300;
	a = 300;

	int const *pp;
	pp = &a;
	pp = &b;
//	*pp = 300;

	//uninitialized const 'ppp'
//	int * const ppp;
	int * const ppp = &a;
//	assignment of read-only variable 'ppp'
//	ppp = &a;
//	ppp = &b;
	*ppp = 300;
}
void f_parents() {
	cout << "new Kids" << endl;
	Parents parents = Kids();
	cout << endl;
	cout << "new Children" << endl;
	Children c = Children();
	c.ch_f1();

	//私有继承不可见对于派生
//	Parents cc = Children((std::string)"LCHJ");
	Children cc = Children((std::string) "LCHJ");
	cc.ch_f1();
	//保护继承不可见对于派生
//	Parents g = Girl((std::string) "LCHJ");
}
