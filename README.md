# Tareas Algebra Abstracta (UCSP)

Todos los códigos se encuentran en la carpeta `src`.

-   `gcd_ext.c`: Algoritmo extendido de Euclides.

-   `prim_root.cpp`: Generador de la raíz primitiva más pequeña.

-   `inverse_mod.cpp`: Generador del inverso modular de un número.

-   `rsa_gen.cpp`: Generador de claves RSA.

    -   `problema2a.py`: Solución al problema 2A de la tarea de RSA.
    -   `problema2b.py`: Solución al problema 2B de la tarea de RSA.

-   `firmas_digitales.py`: Archivo que contiene los siguientes algoritmos:

    -   `miller_rabin()`:

        ```py
        def miller_rabin(n, s):
            t, u = get_t_u(n) # n - 1 == 2**t * u
            for _ in range(1, s+1):
                a = randrange(1, n)
                if witness(a, n, t, u):
                    return True
            return False
        ```

    -   `generate_prime():`

        ```py
        def generate_prime(b):
            s = 128 # hardcoded
            n = generate_prime_candidate(b)
            while miller_rabin(n, s):
                n += 2
            return n
        ```

    -   `rsa_key_generator():`

        ```py
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
        ```
