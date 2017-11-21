//============================================================================
// Name        : cplus.cpp
// Author      : Ogrim
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <exception>
using namespace std;

void f_delete();
void f_new();
void f_default_ref(string s = "lchj") {
	cout << s << endl;
}
string & f_ref() {
	string s = "";
	return s;
}
void f_call_f_ref() {
//	string s = f_ref(); //cause crashing.
}
void f_string() {
	char * a = "";
	char b[] = "";
	string c = "";
	c = a;
	c = b;
	a = b;
//	b=a;
//	a=c;
//	b=c;
}
void f_001() {
	int aa[5][4];
	int aaa[5][4][5];
	int tell[20];
	cout << sizeof tell << endl;
	cout << tell << endl;
	cout << &tell << endl;
	cout << tell + 1 << endl;
	cout << &tell + 2 << endl;
	int a = 3;
	int *pp = &a;
	cout << pp[0] << endl;
	cout << pp[1] << endl;
}
void f_002() {
	char c1[] = "lchj";
	char c2[] = "lchj";
	cout << &c1 << endl;
	cout << (int*) c1 << endl;
	cout << &c2 << endl;
}
void f_ref_const(const int & a) {
	cout << a << endl;
}
void f_const() {
	const int * const p = new int;
	cout << p << endl;
	cout << *p << endl;
//	*p=100;
	int a = 33;
//	p = &a;
	delete p;

	int * const pp = new int;
	*pp = a;
//	pp = &a;

	const int * ppp = new int;
//	*ppp = a;
	ppp = &a;

	int & k = a;
	f_ref_const(k);
}
void f_struct() {
	struct P {
		char name[30];
		int age;
	};
	P p = { "juliana", 20 };
	cout << p.name << endl;
	cout << p.age << endl;
	P * pt = &p;
	cout << pt->name << endl;
	cout << pt->age << endl;
	cout << (*pt).name << endl;
	cout << (*pt).age << endl;
}
void f_for() {
	for (int i = 0; i < 10; i++)
		cout << i << endl;
//	cout << i << endl;
}
void f_alias(int & a) {
	a = 100;
}
void f_alias() {
	int a = 311;
	int & b = a;
	cout << &a << "  " << &b << "  " << a << "  " << b << endl;
	f_alias(a);
	cout << a << "  " << &a << endl;
}

template<typename t>
void f_typename(t & a, t & b) {
	t c;
	c = b;
	b = a;
	a = c;
	cout << "finish f_typename" << endl;
}
void f_call_typename() {
	int a = 10;
	int b = 20;
	f_typename(a, b);
	cout << a << "  " << b << endl;

	string s1 = "ych";
	string s2 = "ogrim";
	f_typename(s1, s2);
	cout << s1 << "  " << s2 << endl;
}

void f_other();

template<class c>
void f_class(c c1, c c2);

template<class T>
T f(T a, T b) {
	return a + b;
}

int global = 1000;
void f_stock();
void f_person();
void call_f_const();
void f_parents();
void f_exception();
void f_cast_0();
void f_typeid();
void define_6();
int main(){
	define_6();
//	f_typeid();
//	f_cast_0();
}
int f_main_0() {
//	f_parents();
//	f_person();
//	call_f_const();
//	f_stock();

//	f_other();

set_terminate(f_parents);
set_unexpected(f_exception);
//	f_call_typename();
//	f_default_ref("yuefei");
//	f_default_ref();
//	f_call_f_ref();
//	f_alias();
//	f_struct();
//	f_const();
//	f_new();

//	f_delete();
	class e {
	public:
		e() {
		}
		;
		virtual void f()=0;
	};
	class u: public e {
	public:
		void f() {
		}
		;
	};
	try {
		char * s = "hahahaha";
		printf("%d\n", s);
		throw s;
	} catch (const char * s) {
		printf("%d\n", s);
		cout << "something is happing. " << s << endl;
	}

	try {
		f_exception();
	} catch (int x) {
		cout << x << endl;
	}
	e * y;
	try {
		u e;
		printf("%d\n", &e);
		throw e;
	} catch (const u & e) {
		printf("%d %d\n", &e);

	}
	try {
		throw 32;
	} catch (...) {
		cout << "soth happend" << endl;
	}
	try {
		throw 3;
	} catch (string s) {

	}
	cout << "end" << endl;
	return 0;
}
void f_exception() {
	throw 300;
}
void f_q() {
	static int global = 10;
	cout << "extern global" << ::global << endl;
	cout << "local global" << global << endl;
	int a = 10;
	double b = 2.2;
	cout << f<double>(a, b) << endl;
}
void f_cin() {
	char name[30];
	cout << "input you name:";
	cin.getline(name, 30);
	cout << "your name" " is " << name << endl;
	cout << "input you name again:";
	cin.get();
	cin.get(name, 30);
	cout << "your name" " is " << name << endl;
}
void f_1() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	std::cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	cout << "\n";
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	cout << 2.0 - 1.1;
	int x = { 9 };
	int y(100);
	//	int w{1000};
	cout << endl;
	cout << x << endl;
	cout << y << endl;
	//	cout<<w<<endl;
	//	cout<<"李顺"<<endl;
	char c = 'x';
	cout << c << endl;
	wcout << L"李顺" << endl;
	wchar_t bc = L'李';
	wcout << bc << endl;
	wcout << L"李顺" << endl;

	printf("%c\n", bc);

	cout << 100 % 5 << endl;
	cout << 11.17 + 50.25 << endl;
	float f1 = 11.17;
	float f2 = 50.25;
	cout << f1 + f2 << endl;
	long long dl = 0x8000ffffbbbbaaaa;
	int di = dl;
	printf("%x\n", di);
	printf("%llx\n", dl);
	cout << sizeof(int) << endl;
	cout << sizeof(short) << endl;
	cout << sizeof(long) << endl;
	cout << sizeof(long long) << endl;
	short ds = di;
	printf("%x\n", ds);
	ds = 30000;
	printf("%x\n", ds);

	//	long long ia = 0x8000000000000000LL;
	long long ia = 0xffffffffffffffffLL;
	unsigned long long ulla = 0;

	cout << ia + ulla << endl;
	printf("%llx\n", ia + ulla);

	long l = static_cast<long>(33);

	auto int z = 10003;
	cout << z << "  " << &z << endl;
}
void f_new() {
	int *p = new int;
	cout << *p << endl;
}

void f_delete() {
	long long *p = new long long;
	*p = 100;
	cout << p << endl;
	delete p;
	cout << p << endl;
	cout << *p << endl;
	long long a = 1000;
	p = &a;
	cout << p << endl;
	delete p;
	cout << p << endl;
	cout << a << endl;
	cout << *p << endl;

	int *pp = new int[10];
	cout << pp << endl;
	delete[] pp;
	cout << pp << endl;

}
