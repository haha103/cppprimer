#include <stdio.h>

int add(int x, int y) {
	while (y != 0) {
		int c = x & y;
		x = x ^ y;
		y = c << 1;
	}
	return x;
}

int main(void) {
	int a = 25;
	int b = 33;
	int result = 0;

	while (b != 0) {
		if(b & 01)
			result = add(result, a);
		b >>= 1;
		a <<= 1;
	}

	printf("%d\n", result);
	
	return 0;
}
