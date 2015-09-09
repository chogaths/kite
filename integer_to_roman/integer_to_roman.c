char* intToRoman(int num) {
    
    int cursor = 0;
	char* res = (char*)malloc(sizeof(char) * 12);

	char* symbol = "IVXLCDM";

	for (int i = 6, power = 1000; i >= 0; i -= 2, num %= power, power /= 10) {

		int digit = num / power;

		if (digit < 4) {
			for (int j = 0; j < digit; j++) {
				res[cursor++] = symbol[i];
			}
		}
		else if (digit == 4) {
			res[cursor++] = symbol[i];
			res[cursor++] = symbol[i + 1];
		}
		else if (digit < 9) {
			res[cursor++] = symbol[i + 1];
			for (int j = 0; j < digit - 5; j++) {
				res[cursor++] = symbol[i];
			}
		}
		else {
			res[cursor++] = symbol[i];
			res[cursor++] = symbol[i + 2];
		}

	}

	res[cursor] = 0;

	return res;
    
}