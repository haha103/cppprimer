#include <iostream>

using namespace std;


struct X {
	X() { cout << "X()" << endl; }
	~X() { cout << "~X()" << endl; }
};

struct Y {
	Y() { cout << "Y()" << endl; }
	~Y() { cout << "~Y()" << endl; }
};

class A {
	X x;
public:
	A() { cout << "A()" << endl; }
	virtual ~A() { cout << "~A()" << endl; }
};

class B : public A {
	Y y;
public:
	B() { cout << "B()" << endl; }
	virtual ~B() { cout << "~B()" << endl; }
};

int main(void) {
	A * b = new B();
	delete b;
}







