/**
* Descriptions: Compute partial sum a[0...r] and update single element a[i]
* Time: O(\logN)
* Source: cp-algo
* Verification: https://judge.yosupo.jp/submission/329393
*/

//INFO : User zero based indexing to query and add
#include <vector>

template <typename T>
struct FenwickTree {
	std::vector<T> bit;
	int n;

	FenwickTree(int n) {
		this->n = n + 1;
		bit.assign(n + 1, 0);
	}

	FenwickTree(std::vector<int> a)
	: FenwickTree(a.size()) {
		for (size_t i = 0; i < a.size(); i++)
			add(i, a[i]);
	}

	T sum(int idx) {
		T ret = 0;
		for (++idx; idx > 0; idx -= idx & -idx)
			ret += bit[idx];
		return ret;
	}

	T sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}

	void add(int idx, T delta) {
		for (++idx; idx < n; idx += idx & -idx)
			bit[idx] += delta;
	}
};
