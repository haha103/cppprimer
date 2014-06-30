#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class SP
{
public:
	SP(T * obj) : _obj(obj), _refcount(new size_t(1)) {
		cout << "object at address " << _obj << " created" << endl;
	}
	~SP()
	{
		cout << "reducing ref count by 1 from " << *_refcount << endl;
		if (--*_refcount == 0) {
			cout << "ref count reached 0, object at address " << _obj << " destroyed" << endl;
			delete _obj;
			delete _refcount;
		}
	}
	SP(const SP<T> & rhs) : _obj(rhs._obj), _refcount(rhs._refcount) {
		++*_refcount;
		cout << "ref count increased to " << *_refcount << endl;
	}

	T & operator*()
	{
		return *_obj;
	}

	T* obj() {
		return _obj;
	}

	size_t refcount() {
		return *_refcount;
	}

	T* operator->()
	{
		cout << "SP accessed like a pointer" << endl;
		return _obj;
	}

	SP<T> & operator=(const SP<T> & rhs) {
		if (this != &rhs) {
			if (--*_refcount == 0) {
				cout << "ref count reached 0, object at address " << _obj << " destroyed" << endl;
				delete _obj;
			}
			_obj = rhs._obj;
			_refcount = rhs._refcount;
			++*_refcount;
			cout << "ref count increased to " << *_refcount << endl;
		}
		return *this;
	}
	
private:
	T * _obj;
	size_t * _refcount;
};

int main(int argc, char * argv [])
{
	SP<vector<int> > sp(new vector<int>(200000));
	sp->push_back(10);
	SP<vector<int> > sp2 = sp;
	SP<vector<int> > sp3(new vector<int>(200000));
	sp3 = sp2;
	cout << sp.obj() << " has been referenced " << sp.refcount() << " times" << endl;
	
	return 0;
}
