/*
 * stock.cpp
 *
 *  Created on: 2017年8月25日
 *      Author: juliana
 */

#include "stock00.h"
#include <iostream>
using namespace std;

int Stock::n = 0;
Stock::Stock(std::string d) {
	this->company = d;
}
Stock::Stock(void) {
	this->company = "default CO";
	this->shares = 10;
	this->share_val = 9.9;
	this->total_val = share_val * shares;
}
Stock::~Stock() {
	cout << "Bye " + this->company << endl;
}
Stock::Stock(const string &co, long int n, double pr) {
	this->company = co;
	if (n < 0) {
		cout << "Number of shares can't be negative;" << this->company << " shares set to 0." << endl;
		this->shares = 0;
	} else {
		shares = 0;
	}
	this->share_val = pr;
	set_tot();
}

void Stock::acquire(const string &co, long int n, double pr) {
	this->company = co;
	if (n < 0) {
		cout << "Number of shares can't be negative;" << this->company << " shares set to 0." << endl;
		this->shares = 0;
	} else {
		shares = 0;
	}
	this->share_val = pr;
	set_tot();
}

void Stock::buy(long int num, double price) {
	if (num < 0) {
		cout << "Number of shares purchased can't be negative. Transaction is aborted." << endl;
	} else {
		this->shares += num;
		share_val = price;
		set_tot();
	}
}

void Stock::sell(long int num, double price) {
	if (num < 0) {
		cout << "Number of shares sold can't be negative. Transaction is aborted.\n";

	} else if (num > shares) {
		cout << "You can't sold more than you have. Transaction is aborted." << endl;
	} else {
		shares = num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price) {
	share_val = price;
	set_tot();
}
Stock Stock::operator+(const Stock & o) const {
	Stock stock;
	stock.company = o.company + "+" + this->company;
	stock.shares = o.shares + this->shares;
	stock.share_val = this->share_val;
	stock.set_tot();
	return stock;
}
Stock Stock::operator+(double m) const {
	Stock stock;
	stock.share_val = this->share_val + m;
	stock.set_tot();
	return stock;
}
//Stock operator+(double m, const Stock & o) {
//	Stock stock;
//	stock.share_val = m + o.share_val;
//	stock.set_tot();
//	return stock;
//}
std::ostream & operator<<(std::ostream & os, const Stock & o) {
	//o.setCo("xzzx"); //友员方法中不能访问共有方法
	//o.set_tot();//友员方法中不能访问私有方法
	os << o.company << "  " << o.total_val << "  ";
	return os;
}
Stock operator+(double m, const Stock & o) {
	return o + m;
}
void Stock::show() const {
	cout << "Company: " << this->company << endl;
	cout << "Shares: " << this->shares << endl;
	cout << "Share Price: " << this->share_val << endl;
	cout << "Total Worthl: " << this->total_val << endl;

}

Person::Person(const Person & p) {
	cout << "copy func." << endl;
}
Person & Person::operator =(const Person & p) {
	cout << "= func." << endl;
	return *this;
}
Parents::Parents(double d) :
		d(d), ci(5) {
}
