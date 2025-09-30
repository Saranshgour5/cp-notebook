#include <vector>
#include <cassert>
template <typename T, class Comp>
class SparseTable 
{
public:
	SparseTable(const std::vector<T>& arr) {
		build(arr);
	}

	T query(int l, int r) const {
		assert(0 <= l && l <=r && r < MAXN);
		int i = log2_floor(r - l + 1);
		T x = st[i][l];
        	T y = st[i][r - (1 << i) + 1];
		return comp(y, x) ? y : x;
	}

private:
	int MAXN {};
	int K {};
	std::vector<std::vector<T>> st {};
	Comp comp; //comparator for "less" or "greater"
	
	int log2_floor(unsigned long long i) const {
	    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
	}

	void build(const std::vector<T>& arr) {
		MAXN = static_cast<int>(arr.size());	
		assert(MAXN > 0);
		K = log2_floor(MAXN);

		st.assign(K + 1, std::vector<T>(MAXN));
		std::copy(arr.begin(), arr.end(), st[0].begin());

		for (int i = 1; i <= K; i++) {
    			for (int j = 0; j + (1 << i) <= MAXN; j++) {
              			T left = st[i - 1][j];
                		T right = st[i - 1][j + (1 << (i - 1))];
                		st[i][j] = comp(right, left) ? right : left;
			}
		}
	}
};
