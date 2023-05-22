from math import gcd


def solve(valor):
    lista = []
    mmc = 1

    for i in range(1, valor+1):
        lista.append(i)

    for j in lista:
        mmc = (mmc * j) // gcd(mmc, j)

    print(mmc)


while True:
    try:
        valor = int(input())
        solve(valor)
    except EOFError:
        break
