#include<bits/stdc++.h>
 
using namespace std;

template<int N>
struct math {
	vector <int> primes;
	array <int, N + 1> spf, mu;

	math() : spf() {
		for (int i = 2; i * i <= N; i++) {
			if (spf[i]) continue;
			for (int j = i * i; j <= N; j += i) {
				if (!spf[j]) spf[j] = i;
			}
		}
		for (int i = 2; i <= N; i++) {
			if (!spf[i]) {
				primes.emplace_back(i);
				spf[i] = i;
				mu[i] = 1;
			} else {
				if ((i / spf[i]) % spf[i] == 0) mu[i] = 0;
				else mu[i] = -mu[i / spf[i]];
			}
		}
	}

	bool is_prime(int x) const {
		return spf[x] == x;
	}

	vector <pair<int, int>> prime_factors(int x) const {
		vector <pair<int, int>> factors;
		while (x != 1) {
			if (factors.empty() || factors.back().first != spf[x]) {
				factors.emplace_back(spf[x], 0);
			}
			factors.back().second++;
			x /= spf[x];
		}
		return factors;
	}

	vector <int> divisors(int x) const {
		vector <int> divisors = {1};
		while (x > 1) {
			int p = spf[x], c = 0;
			while (x % p == 0) {
				x /= p, c += 1;
			}
			int sz = (int) divisors.size();
			for (int i = 1, pw = p; i <= c; i++, pw *= p) {
				for (int j = 0; j < sz; j++) {
					divisors.push_back(divisors[j] * pw);
				}
			}
		}
		return divisors;
	}

	vector <int> unique_divisors(int x) const {
		vector <int> divisors, unique_divisors = {1};
		while (x != 1) {
			if (divisors.empty() || divisors.back() != spf[x]) {
				divisors.emplace_back(spf[x]);
			}
			x /= spf[x];
		}
		for (int i = 0; i < divisors.size(); i++) {
			int sz = (int) unique_divisors.size();
			for (int j = 0; j < sz; j++) {
				unique_divisors.push_back(divisors[i] * unique_divisors[j]);
			}
		}
		return unique_divisors;
	}
};

math <1000 * 1000> s;

int main(){
    cout << "Hello World\n";
    return 0;
}