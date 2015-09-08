bool isMatch(char* s, char* p) {
    
    if (!*p) {
		return !*s;
	}

	if (*(p + 1) == '*') {
		while (*s && *p == '.' || *s == *p) {
			if (isMatch(s, p + 2)) {
				return true;
			}
			s++;
		}
		return isMatch(s, p + 2);
	}

	else if (*s && *p == '.' || *s == *p) {
		return isMatch(s + 1, p + 1);
	}

	return false;
    
}