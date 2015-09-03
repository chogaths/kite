#include <limits.h>

int reverse(int x) {

	bool negative = x < 0;

	if (negative) {
		x = -x;
	}

	int res = 0;

	while (x) {
		int n = x % 10;
		x /= 10;
		if ((INT_MAX - n) / 10 < res) {
			return 0;
		}
		res = res * 10 + n;
	}

	if (negative) {
		res = -res;
	}

	return res;

}