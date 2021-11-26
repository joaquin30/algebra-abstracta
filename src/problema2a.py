from math import sqrt
e = 65537
n = 999630013489
p = 1
q = 1

for i in range(int(sqrt(n)) + 1, 0, -2):
    if n % i == 0:
        p = i
        q = n // i
        break

phi = (p-1) * (q-1)
d = pow(e, -1, phi)

c = 747120213790
m = pow(c, d, n)
print(m)
