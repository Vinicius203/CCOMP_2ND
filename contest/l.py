import math

a, b, c = map(float, (input().split()))

if a == 0:
    print('Nulo')
else:
    bhaskara = (b * b) - 4 * a * c
    if bhaskara < 0:
        print('Nulo')
    elif bhaskara == 0:
        raiz = (b * - 1) / (2 * a)
        print(f'{raiz:.2f} {raiz:.2f}')
    else:
        raiz = ((b * - 1) + (math.sqrt(bhaskara))) / (2 * a)
        raiz2 = ((b * - 1) - (math.sqrt(bhaskara))) / (2 * a)
        print(f'{raiz:.2f} {raiz2:.2f}')   