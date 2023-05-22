import math as m

a, b, c, d, e, f = tuple([int(x) for x in input().split()])

y = ((f*a) - (d*c)) / ((-b*d)+(a*e))
x = (c - (b*y))/a

print(f"{x:.2f} {y:.2f}")
