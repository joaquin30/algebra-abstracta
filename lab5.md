% Laboratorio 5

1.  Sea $ax \equiv 1 \pmod{n}$, implementar un algoritmo para calcular $x$ (el
    inverso multiplicativo de $a$, módulo $n$). El programa debe permitir
    ingresar el número $a$ y $n$, luego debe retornar el valor de $x$ (si es
    que existe). Crear un repositorio en GitHub (con `README.md`).

    - Repositorio: <https://github.com/joaquin30/algebra-abstracta>.
    - Archivo: `inverse_mod.cpp`.

2.  Resolver utilizando *El pequeño teorema de Fermat*.

    (a) $3^{181} \bmod 7$.

        $$\begin{aligned}
        {} = {} &3 \left(3^{6 \cdot 30} \bmod 7\right) \\
        {} = {} &3
        \end{aligned}$$

    (b) $2^{245} \bmod 7$.

        $$\begin{aligned}
        {} = {} &\left(2^{6 \cdot 40} \bmod 7\right) \left(2^5 \bmod 7
        \right) \\
        {} = {} &32 \bmod 7 \\
        {} = {} &4
        \end{aligned}$$

    (c) $128^{129} \bmod 17$.

        $$\begin{aligned}
        {} = {} &\left(128 \bmod 17\right)^{129} \bmod 17 \\
        {} = {} &9^{129} \bmod 17 \\
        {} = {} &9 \left(9^{16 \cdot 8} \bmod 17\right) \\
        {} = {} &9
        \end{aligned}$$

    (d) ¿Cuál es el residuo de dividir $2^{1000}$ entre 13?

        $$\begin{aligned}
        {} = {} &\left(2^{12 \cdot 83} \bmod 13\right)\left(2^4 \bmod
        13\right) \\
        {} = {} &16 \bmod 13 \\
        {} = {} &3
        \end{aligned}$$

    (e) $(2^{20} + 3^{30} + 4^{40} + 5^{50} + 6^{60}) \bmod 7$.

        $$\begin{aligned}
        {} = {} &\left(2^{6 \cdot 3} \bmod 7 + 2^2 \bmod 7 + 3^{6 \cdot 5}
        \bmod 7 + {} \right.\\
        & 4^{6 \cdot 6} \bmod 7 + 4^4 \bmod 7 + 5^{6 \cdot 8} \bmod 7 + {}\\
        & \left. 5^2 \bmod 7 + 6^{6 \cdot 10} \bmod 7\right) \bmod 7 \\
        {} = {} &(1 + 4 + 1 + 1 + 4 + 1 + 4 + 1) \bmod 7 \\
        {} = {} &17 \bmod 7 \\
        {} = {} &3
        \end{aligned}$$

3.  Resolver $x^{103} \equiv 4 \pmod{11}$, para $0 \leq x \leq 11$.

    $$\begin{aligned}
    x^{103} \bmod 11 &= 4 \\
    x^{10 \cdot 10} + x^3 \bmod 11 &= 4\\
    x^3 \bmod 11 &= 4 \\
    x &= 5
    \end{aligned}$$

4.  Un *googol* es igual a $10^{100}$, un número tan grande que supera la
    cantidad de átomos en el universo ($\approx 10^{80}$). Ahora, un
    *googolplex* es igual a $10^{\text{googol}}$. ¿Que día de la semana sería
    un *googolplex* de días a partir de ahora? (Hoy es viernes).

    $$\begin{aligned}
    10^x &\equiv \text{googolplex} \pmod{7} \\
    3^x &\equiv \text{googolplex} \pmod{7} \\
    x &\equiv \text{googol} \pmod{6} \\
    x &\equiv 2^{200} \pmod{6}
    \end{aligned}$$

    Al analizar los valores de $\left\{2^x\bmod 6\mid x \in \mathbb{N}\right\}$
    notamos que se repiten dos valores hasta el infinito ($\left\{2,4,2,4,
    \dots\right\}$), por lo que podemos deducir facilmente el valor basandonos
    en la paridad.

    $$\begin{aligned}
    x &\equiv 4 \pmod{6} \\
    3^4 &\equiv \text{googolplex} \pmod{7} \\
    4 &\equiv \text{googolplex} \pmod{7}
    \end{aligned}$$

    Entonces la respuesta es viernes más 4 días, que es martes.
