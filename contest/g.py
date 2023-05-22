while True:
        try:
            n = int(input())
            r = ((n*(n+1))//2)
            print(r)
        except EOFError:
            break