#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

void printarray(int * a, size_t n) {
	copy(a, a + n, ostream_iterator<int>(cout, " "));
	//for (int i = 0; i < n; ++i)
	//	cout << a[i] << " ";
	//cout << endl;
}

void quicksort(int * a, size_t start, size_t end) {
	int pivot = a[start];
	size_t tmp = start;
	swap(a[start], a[end]);
	for (int i = start; i < end; ++i) {
		if (a[i] <= pivot) {
			swap(a[i], a[tmp]);
			++tmp;
		}
	}
	swap(a[end], a[tmp]);
	if (start + 1 < tmp)
		quicksort(a, start, tmp - 1);
	if (tmp + 1 < end)
		quicksort(a, tmp + 1, end);
}

int main(void)
{
	int a[] = {8,7,2,4,9,1,3};
	quicksort(a, 0, 6);
	printarray(a, 7);
	
	return 0;
}










