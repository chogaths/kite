int findKth(int* l, int ls, int* r, int rs, int k) {

	if (ls > rs) {
		return findKth(r, rs, l, ls, k);
	}

	if (ls == 0) {
		return r[k - 1];
	}

	if (k == 1) {
		return l[0] < r[0] ? l[0] : r[0];
	}

	int lk = k / 2 < ls ? k / 2 : ls;
	int rk = k - lk;

	if (l[lk - 1] < r[rk - 1]) {
		return findKth(l + lk, ls - lk, r, rs, k - lk);
	}
	else if (l[lk - 1] > r[rk - 1]) {
		return findKth(l, ls, r + rk, rs - rk, k - rk);
	}
	else {
		return l[lk - 1];
	}
	
}

double findMedianSortedArrays(int* l, int ls, int* r, int rs) {
    
    if ((ls + rs) &0x01) {
        return findKth(l, ls, r, rs, (ls+rs)/2+1);
    } else {
        return (double)(findKth(l, ls, r, rs, (ls+rs)/2) + findKth(l, ls, r, rs, (ls+rs)/2+1))/2;
    }
    
}