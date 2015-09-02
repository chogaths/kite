#include <stdlib.h>
#include <string.h>

#define max_sl 1000
#define max_rl (max_sl*2+1+2+1)

char* manacher(char *s) {

	int rl = 0;
	char* r = (char*)malloc(sizeof(char) * max_rl);
	r[0] = '$';
	for (; s[rl]; rl++) {
		r[rl * 2 + 1] = '#';
		r[rl * 2 + 2] = s[rl];
	}
	rl = rl * 2 + 1;
	r[rl] = '#';
	r[rl + 1] = '^';
	r[rl + 2] = 0;

	int ml = 0;
	int mi = 0;

	int pi = 0;
	int* mp = (int*)malloc(sizeof(int)*rl);
	memset(mp, 0, sizeof(int)*rl);

	for (int i = 1; i < rl; i++) {

		if (ml > i) {
			mp[i] = mp[2 * mi - i] > ml - i ? ml - i : mp[2 * mi - i];
		}
		else {
			mp[i] = 1;
		}

		for (; r[i + mp[i]] == r[i - mp[i]]; mp[i]++);

		if (i + mp[i] > ml) {
			ml = i + mp[i];
			mi = i;
		}

		if (mp[pi] < mp[i]) {
			pi = i;
		}

	}

	int l = mp[pi] - 1;
	int p = (pi - mp[pi]) / 2;
	char* res = (char*)malloc(sizeof(char)*l + 1);
	memcpy(res, s + p, sizeof(char)*l);
	res[l] = 0;

	return res;

}