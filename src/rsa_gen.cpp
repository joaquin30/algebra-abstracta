#include <iostream>
#include <array>
#include <vector>
#include <utility>
#include <random>
#include <string>

using int3 = std::array<int, 3>;

int3 gcdExt(int a, int b) {
    if (b == 0)
        return {a, 1, 0};
    auto tmp = gcdExt(b, a%b);
    return {
        tmp[0],
        tmp[2],
        tmp[1] - tmp[2] * (a / b)
    };
}

int modExp(int base, int exp, int mod) {
    int res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1)
            res = (res % mod * base % mod) % mod;
        exp >>= 1;
        base = (base % mod * base % mod)%mod;
    }
    return res;
}

class RSAGenerator {
    // pueden ser otros primos
    const int p = 3, q = 11;
    std::mt19937 rng;

public:
    RSAGenerator() : rng(std::random_device()()) {}
    int3 gen() {
        int n = p * q;
        int phi_n = (p -1) * (q - 1);
        std::uniform_int_distribution<> uid(2, n - 1);
        int e;
        int3 gcd;
        do {
            e = uid(rng);
            gcd = gcdExt(e, phi_n);
        } while (gcd[0] != 1);
        // inverso modular de e
        int d = (gcd[1] % phi_n + phi_n) % phi_n;
        return {n, e, d};
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    RSAGenerator rsa;
    auto key = rsa.gen();
    std::cout << "Clave RSA: n = " << key[0]
        << " e = " << key[1]
        << " d = " << key[2] << "\n";
    int cnt = 0;
    std::vector<std::string> c1 {"m"}, c2 {"c"};
    for (int m = 0; m < key[0]; ++m) {
        int c = modExp(m, key[1], key[0]);
        if (m == c) {
            c1.push_back("**" + std::to_string(m) + "**");
            c2.push_back("**" + std::to_string(c) + "**");
        } else {
            c1.push_back(std::to_string(m));
            c2.push_back(std::to_string(c));
        }
    }

    // output to csv
    for (auto i : c1)
        std::cout << i << ",";
    std::cout << "\n";
    for (auto i : c2)
        std::cout << i << ",";
    std::cout << "\n";
}