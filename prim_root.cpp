#include <iostream>
#include <vector>
#include <array>
using namespace std;
using ll = long long;

vector<ll> primeFactors(ll n)
{
    vector<ll> res;
    if (n % 2 == 0) {
        res.push_back(2);
        while (n % 2 == 0)
            n = n / 2;
    }

    for (ll i = 3; i * i <= n; i += 2){
        if (n % i == 0) {
            res.push_back(i);
            while (n % i == 0)
                n /= i;
        }
    }

    if (n > 2)
        res.push_back(n);

    return res;
}

ll modexp(ll base, ll exp, ll mod)
{
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1)
            res = (res % mod * base % mod) % mod;
        exp >>= 1;
        base = (base % mod * base % mod)%mod;
    }

    return res;
}

ll primitiveRoot(ll n)
{
    auto primes = primeFactors(n-1);
    for (ll& i: primes)
        i = (n - 1) / i;

    for (ll i = 2; i < n; ++i) {
        bool pass = true;
        for (ll j : primes) {
            if (modexp(i, j, n) == 1) {
                pass = false;
                break;
            }
        }

        if (pass)
            return i;
    }

    return -1;
}

int main()
{
    ll n = 100049, g = primitiveRoot(n), a = 2021;
    cout << "La raiz primitiva mas pequeña de " << n << " es: " << g << "\n";
    for (ll i = 1; i < n; ++i) {
        if (modexp(g, i, n) == a) {
            cout << "Si " << g << "^x mod " << n << " = " << a
                 << ", entonces x = " << i << "\n";
            break;
        }
    }

	return 0;
}