#include <iostream>

using namespace std;


class A {
public:
	virtual void f1() { cout << "f1 in A" << endl; }
	void f2() { cout << "f2 in A" << endl; }
};

class B : public A {
public:
	virtual void f1() { cout << "f1 in B" << endl; }
	void f2() { cout << "f2 in B" << endl; }
};

int main(void) {
	B b;
	A * a = &b;
	a->f1();
	a->f2();
	return 0;
}
