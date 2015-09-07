bool isPalindrome(int x) {

	if (x < 0) {
		return false;
	}

	long long y = 0;
	for (int z = x; z; z /= 10) {
		y = y * 10 + z % 10;
	}

	return y == x;

}

bool isPalindrome2(int x) {

	if (x < 0) {
		return false;
	}

	int power = 1;
	for (; x / power >= 10; power *= 10);

	for (; x; x = x % power / 10, power /= 100) {
		if (x % 10 != x / power) {
			return false;
		}
	}

	return true;
}