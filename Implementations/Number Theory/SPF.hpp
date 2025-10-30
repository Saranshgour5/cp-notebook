/*
 * Description: Calculate the Smallest prime factor for i < SZ
 * Time: O(SZ\log\log(SZ))
 * Source: https://codeforces.com/topic/141399/en4
 * Verification: https://codeforces.com/contest/2154/problem/C2
 * */

template<int SZ> struct SPF
{
	int spf[SZ] {};
	SPF() {
		static_assert(SZ > 0, "Size should be greater than 0");
		for(int i {1}; i < SZ; ++i)
			spf[i] = i;

		for(int i{2}; i < SZ; ++i)
		{
			if(i != spf[i])continue;
			for(int j{i * i}; j < SZ; j += i)
			{
				if(spf[j] == j)
					spf[j] = i;
			}
		}
	}
};
