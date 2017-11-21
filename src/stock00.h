/*
 * stock00.h
 *
 *  Created on: 2017年8月25日
 *      Author: juliana
 */
#include <string>
#include <iostream>
#ifndef STOCK00_H_
#define STOCK00_H_
using namespace std;
class Lawer {
	std::string name;
public:
	void set_name(const std::string & s) {
		this->name = s;
	}
};

class Stock {

private:
	std::string company;
	static const int n1 = 10;
	static int n;
	long shares;
	double share_val;
	double total_val;
	void set_tot(void) {
		total_val = shares * share_val;
	}
public:
	Lawer lawer;
	void acquire(const std::string & co, long n, double pr);
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	void show() const;
	Stock operator+(const Stock & o) const;
	Stock operator+(double m) const;
	void setCo(const std::string &co) {
		this->company = co;
	}
	Stock(const std::string &co, long int n, double pr);
	Stock(std::string d);
//	explicit Stock(std::string d);
	Stock(void);
	~Stock();
//	friend Stock operator+(double m, const Stock & o);
	friend std::ostream & operator<<(std::ostream & os, const Stock & o);
};
Stock operator+(double m, const Stock & o);
//Stock::Stock(const std::string &co, long int n, double pr);

class Person {
private:
public:
	std::string name;
	Person() {
	}
	;
	Person(const Person & p);
	Person & operator=(const Person & p);
};
class C {
private:
public:
	C() {
		std::cout << "C default constructor" << std::endl;
	}
	C(char * s) {
		std::cout << "C s constructor" << std::endl;
		this->s = s;
	}
	C(const C & s) {
		std::cout << "C const &s constructor" << std::endl;
		this->s = s.s;
	}
	C(C & s) {
		std::cout << "C &s --- constructor" << std::endl;
		this->s = s.s;
	}
//	invalid constructor C(C s)
//	C(C s) {
//		std::cout << "C &s --- constructor" << std::endl;
//		this->s = s.s;
//	}
	std::string s;
	operator std::string() {
		return this->s;
	}
};
class B {
	int b;
public:
	void f1() {
		b = 300;
	}
	;
	void f() const {
		//assignment of member 'B::b' in read-only object;
//		b = 100;
	}
	;
};
class D {
};

class StockSub: public Stock {

};
class StockSub1: Stock {

};

class Parents {
private:
	static int si;
	static const int sci = 90;
	int ci;
	double d;
	std::string s;
	void pf() {
		cout << ci << endl;
	}
public:
	double pd;
	Parents() {
		cout << "Parents constructor" << endl;
	}
	;
	static void sf() {
		si = 9;
	}
	Parents(int x) :
			ci(3), d(3.3), s(NULL) {
		si = 300;
	}
	;
	Parents(string s) :
			ci(5), s(s) {
		cout << "Parents string constructor" << endl;
		d = 3.2;
		pd = 4.4;
	}
	;
	Parents(double d);
	void p() {
		cout << pd << endl;
	}
};
class Kids: public Parents {
private:
	int k_int;
public:
	Kids() {
		cout << "Kids constructor" << endl;
		k_int = 299;
	}
	;
	void kids_f1() {
		cout << pd << endl;
		p();
	}
};
class Children: private Parents {
private:
	int k_int;
public:
	Children() {
		k_int = 200;
		cout << "Children constructor" << endl;
	}
	;
	Children(string x) :
			Parents(x) {
		k_int = 200;
		cout << "Children string constructor" << endl;
	}
	void ch_f1() {
		Parents::pd = 300.3;
		cout << pd << endl;
		p();
		Parents::p();
		Parents cc = Children((std::string)"LCHJ");
	}
};
class Girl: protected Parents {
private:
	int k_int;
public:
	Girl() {
		k_int = 200;
		cout << "Girl constructor" << endl;
	}
	;
	Girl(string x) :
			Parents(x) {
		k_int = 200;
		cout << "Girl string constructor" << endl;
	}
	void ch_f1() {
		Parents::pd = 300.3;
		cout << pd << endl;
		p();
		Parents::p();
		Parents g = Girl((std::string) "LCHJ");
	}
};
class myos: std::ostream {

};

#endif /* STOCK00_H_ */
