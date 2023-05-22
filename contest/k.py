while True:
    try:
        n, m = map(float, (input().split()))
        r = 0

        if n < m:
            r = m + n / 2
        else:
            r = n + m / 2

        print(f'{r:.2f}')
    except EOFError:
     break
