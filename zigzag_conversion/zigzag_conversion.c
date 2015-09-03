char* convert(char* s, int numRows) {

	if (numRows < 2) {
		return s;
	}

	int slen = 0;
	for (; s[slen]; slen++);

	int cursor = 0;
	char* res = (char*)malloc(sizeof(char)*(slen + 1));
	res[slen] = 0;

	int size = numRows * 2 - 2;

	for (int i = 0; i < numRows; i++) {
		for (int j = i; j < slen; j += size) {
			res[cursor++] = s[j];
			if (i != 0 && i != numRows - 1) {
				int index = j + size - i * 2;
				if (index < slen) {
					res[cursor++] = s[index];
				}
			}
		}
	}

	return res;

}