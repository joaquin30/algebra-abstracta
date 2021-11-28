from random import randrange, getrandbits, choice
from hashlib import sha1

def witness(a, n, t, u):
    x0 = pow(a, u, n)
    if x0 == 1 or x0 == n-1:
        return False
    for _ in range(1, t+1):
        x1 = (x0*x0) % n
        if x1 == n - 1:
            return False
        x0 = x1
    return True

def get_t_u(n):
    # n - 1 == 2 ** t * u
    n -= 1
    t = 0
    while n%2 == 0:
        n //= 2
        t += 1
    return t, n

def miller_rabin(n, s):
    t, u = get_t_u(n)
    for _ in range(1, s+1):
        a = randrange(1, n)
        if witness(a, n, t, u):
            return True
    return False

def generate_prime_candidate(b):
    n = getrandbits(b+1) # last bit is for sign
    m = 2**(b-1) + 1
    n |= m
    return n

def generate_prime(b):
    s = 128 # hardcoded
    n = generate_prime_candidate(b)
    while miller_rabin(n, s):
        n += 2
    return n

def rsa_key_generator(b):
    e = choice([3, 5, 17, 257, 65537])
    p = generate_prime(b//2)
    while p%e == 1:
        p = generate_prime(b//2)
    q = generate_prime(b//2)
    while q%e == 1 and p != q:
        q = generate_prime(b//2)
    n = p*q
    phi = (p-1) * (q-1)
    d = pow(e, -1, phi) # inverse mod
    return n, e, d

def randstr(size):
    digits = '0123456789abcdef'
    return ''.join(choice(digits) for _ in range(size))

def pkcs15(m, bm, bn):
    return '0002' + randstr(bn//4 - bm//4 - 3) + '00' + m

def print_iter(iter):
    cnt = 0
    for i in iter:
        print(i, end=' ')
        cnt += 1
        if cnt == 10:
            print()
            cnt = 0

def main():
    # Miller Rabin
    print('''
Números primos de 3 cifras
==========================
''')
    primes = []
    for i in range(100, 1000):
        if not miller_rabin(i, 128):
            primes.append(i)
    print_iter(primes)

    # Generate Prime
    print('''


100 primos distintos de 10 bits
===============================
''')
    primes = set([])
    while len(primes) < 100:
        primes.add(generate_prime(10))
    print_iter(primes)

    # RSA Key Generator
    print('''

Prueba clave RSA
================
''')
    n, e, d = rsa_key_generator(10)
    for m in [45, 436, 233]:
        c = pow(m, e, n)
        print(f'm = {m}  S(m) = {c}  P(S(m)) = {pow(c, d, n)}')
    n, e, d = rsa_key_generator(160)
    msg = 'Hola mundo!'
    m = int(sha1(msg.encode()).hexdigest(), 16)
    c = pow(m, e, n)
    print(f'''
msg = {msg}
msg (hashed) = {m}
S(msg) = {c}
P(S(msg)) = {pow(c, d, n)}''')

    # Firma Digital de 256 bits
    n, e, d = rsa_key_generator(256)
    msg = 'Joaquín Felipe Pino Zavala'
    m = sha1(msg.encode()).hexdigest()
    print(f'''

Firma Digital de 256 bits
=========================

Firma: {msg}
Firma (hashed) {m}''')
    m = pkcs15(m, 160, 256)
    print(f'Firma (PKCS #1 1.5): {m}')
    m = int(m, 16)
    c = pow(m, e, n)
    print(f'''
m = {m}
S(m) = {c}
P(S(m)) = {pow(c, d, n)}
''')


if __name__ == '__main__':
    main()
