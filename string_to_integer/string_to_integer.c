int myAtoi(char* str) {

	double res = 0.;
	bool negative = false;

	for (; str[0] == ' '; str++);

	if (str[0] == '-') {
		negative = true;
		str++;
	}
	else if (str[0] == '+') {
		str++;
	}

	for (; str[0] >= '0' && str[0] <= '9'; str++) {
		res = res * 10 + str[0] - '0';
	}

	res = negative ? -res : res;
	return res < INT_MIN ? INT_MIN : (res > INT_MAX ? INT_MAX : (int)res);

}