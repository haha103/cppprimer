#include <iostream>

using namespace std;

struct A {
	A() {
		cout << "ctor" << endl;
	};
	A(const A & rhs) {
		cout << "copy ctor" << endl;
	}
	~A() {
		cout << "dtor" << endl;
	}
	A & operator=(const A & rhs) {
		cout << "assignment operator" << endl;
		return *this;
	}
};

int main(void) {
	A a1;
	A a2;
	A a3(a2);
	a3 = a1;
	cout << "done" << endl;
	return 0;
}
