#include <iostream>
#include <array>
using namespace std;

using ull = unsigned long long;
using ull3 = array<ull, 3>;

ull3 gcdExt(ull a, ull b)
{
    if (b == 0)
        return {a, 1, 0};

    auto tmp = gcdExt(b, a%b);
    return {
        tmp[0],
        tmp[2],
        tmp[1] - tmp[2] * (a / b)
    };
}

int main()
{
    /*
    test
    a = 7241718167
    mod = 8175093213153651137
    */
    string hola;
    ull a, mod;
    puts("Ingresa a y n para hallar x "
        "en ax = 1 (mod n)");
    scanf("%llu%llu", &a, &mod);
    auto b = gcdExt(a, mod);

    if (b[0] != 1)
    {
        puts("No se encontró un inverso modular");
    }
    else
    {
        ull x = (b[1] % mod + mod) % mod;
        printf("El inverso modular de %llu mod %llu es %llu\n",
            a, mod, x);
    }

	return 0;
}