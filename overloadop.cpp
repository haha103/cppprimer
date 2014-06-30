#include <iostream>

using namespace std;


class Date {
private:
	int _y, _m, _d;
public:
	Date(int y, int m, int d) : _y(y), _m(m), _d(d) {}
	friend ostream & operator<<(ostream & os, const Date & dt);
};

ostream & operator<<(ostream & os, const Date & dt) {
	os << dt._y << "-" << dt._m << "-" << dt._d;
	return os;
}

int main(void) {
	Date dt(2011, 3, 4);
	cout << dt << endl;
}
