/**
* Descriptions: Tests primality upto SZ
* Time: O(SZ\log\log SZ)
* Source: https://github.com/bqi343/cp-notebook/
* */

#include <cassert>
#include <vector>
#include <bitset>

template<int SZ> struct Sieve {
	std::bitset<SZ> is_prime;
	std::vector<int> primes;
	Sieve() {
		static_assert(SZ > 0);
		is_prime.set(); is_prime[0] = is_prime[1] = 0;
		for (int i {4}; i < SZ; i += 2)
			is_prime[i] = 0;

		for (int i {3}; i*i < SZ; i += 2) 
		{
			if (is_prime[i])
			{
				for (int j = i*i; j < SZ; j += i*2)
					is_prime[j] = 0;
			}
		}
		for(int i {}; i < SZ; ++i) 
			if (is_prime[i]) primes.push_back(i);
	}
};
